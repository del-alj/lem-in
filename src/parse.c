/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:42:07 by mzaboub           #+#    #+#             */
/*   Updated: 2020/11/02 09:55:26 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"
#define BUFF_READ 10000

int		ft_get_room_info(char *str, int i, t_data *data)
{
	str[i] = '\0';
	data->room = str;
	str = str + i + 1;
	data->x = ft_atoi(str);
	if (*str == '-' || *str == '+')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (ft_isspace((int)*str) != 1)
		return (-1);
	++str;
	data->y = ft_atoi(str);
	if (*str == '-' || *str == '+')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (*str != '\0')
		return (-1);
	return (1);
}

/*
** ---------------------------------------------------------------------------
*/

int		ft_get_edge_info(char *str, int i, t_data *data)
{
	str[i] = '\0';
	data->room = str;
	str = str + i + 1;
	i = 0;
	while ((str[i]) && (ft_isspace(str[i]) != 1) && (str[i] != '-'))
		i++;
	if (str[i] != '\0')
		return (-1);
	data->adj_room = str;
	return (2);
}

/*
** ---------------------------------------------------------------------------
*/

int		ft_check_line(char *str, t_data *data, t_box *head)
{
	int i;

	i = 0;
	if (str[0] == '#')
	{
		if (((ft_strequ(str, "##start") == 1) && head->start != NULL) || \
				((ft_strequ(str, "##end") == 1) && head->end != NULL))
			return (-1);
		if (ft_strequ(str, "##start") == 1)
			data->var = 'S';
		else if (ft_strequ(str, "##end") == 1)
			data->var = 'E';
	}
	else
	{
		while ((str[i]) && (ft_isspace(str[i]) != 1) && (str[i] != '-'))
			i++;
		if (str[i] && str[i] == '-')
			return (ft_get_edge_info(str, i, data));
		else if (str[i])
			return (ft_get_room_info(str, i, data));
		else
			return (-1);
	}
	return (0);
}

/*
** ****************************************************************************
*/

void	ft_read_all_file(char **str, int *length, char **backup_buff)
{
	char	buff[BUFF_READ + 1];
	char	*temp;
	int		ret;

	if (!(*str = (char*)ft_memalloc(BUFF_READ + 1)))
		exit(EXIT_FAILURE);
	ret = read(0, *str, BUFF_READ);
	(*str)[ret] = '\0';
	*length = ret;
	while ((ret = read(0, buff, BUFF_READ)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(*str, buff);
		if (!temp)
			exit(0);
		ft_memdel((void**)str);
		*str = temp;
		*length += ret;
		if (ret < BUFF_READ)
			break ;
	}
	if ((*backup_buff = ft_strdup(*str)) == NULL)
		exit(EXIT_FAILURE);
}

/*
** ****************************************************************************
*/

int		ft_update_next_start(char *str, int *idx, int stop)
{
	int		start;

	start = *idx;
	while ((*idx < stop) && str[*idx] != '\n')
		(*idx)++;
	str[*idx] = '\0';
	++*idx;
	return (start);
}

/*
** ****************************************************************************
** if (its a comment retrun 0)
** else if its something rather then a number or a big number return ERROR (-1)
** else read the number and return true
*/

int		get_ants_num(char *str, int *number_of_ants)
{
	if ((*str == '#') && ft_strequ(str, "##start") == 0 && \
			ft_strequ(str, "##end") == 0)
		return (0);
	else if ((*str == '-') || (ft_isstr_digit(str) == 0) || \
			(ft_str_numbercmp(str, "2147483647") > 0) || \
			(ft_str_numbercmp(str, "0") == 0))
		return (-1);
	if ((*number_of_ants = ft_atoi(str)) == 0)
		return (-1);
	return (1);
}

/*
** ****************************************************************************
*/

void	ft_add_room(t_box *head, t_data *data, int bol, char **str)
{
	if (bol == 2)
	{
		ft_memdel((void**)str);
		ft_error_function(head->tree, "\tin ROOM DEFINED AFTER AN EDGE.");
	}
	if ((head->tree) != NULL)
		ft_insert_node(&(head->tree), *data, head);
	else
	{
		(head->tree) = ft_new_node(*data);
		ft_if_start_end(head->tree, *data, head);
	}
	data->var = 'M';
}

/*
** ****************************************************************************
** reads all the input string and saves it to a propre data structure
** take care of deplacates start and end :: stops the programe bcs it's an error
** saves all the rooms and edges
*/

int		ft_save_rooms_and_edges(int index, char *str, int stop, t_box *head)
{
	int		start;
	int		bol;
	int		var;
	t_data	data;

	bol = 1;
	data.var = 'M';
	while (index < stop)
	{
		start = ft_update_next_start(str, &index, stop);
		if (str[start] == 'L')
			ft_error_function(head->tree, "in LINE INFO");
		var = ft_check_line(str + start, &data, head);
		if (var == -1 || (data.var == 'S' && head->start) || \
				(data.var == 'E' && head->end))
		{
			ft_memdel((void**)&str);
			ft_error_function(head->tree, "\tin LINE INFO.");
		}
		else if (var == 1)
			ft_add_room(head, &data, bol, &str);
		else if ((var == 2) && (bol = 2))
			ft_add_edge(&(head->tree), data.room, data.adj_room);
	}
	return (bol);
}

/*
** ****************************************************************************
** read all the input at once and keep it in two separate buffers
** escap the comments at start tell you find the ants number
*/

int		ft_read_input(t_box *head, char **buff)
{
	int		bol;
	char	*str;
	int		stop;
	int		index;
	int		start;

	bol = 0;
	index = 0;
	ft_read_all_file(&str, &stop, buff);
	while (bol == 0)
	{
		start = ft_update_next_start(str, &index, stop);
		bol = get_ants_num(str + start, &(head->ants_nbr));
		if (bol == -1)
		{
			ft_memdel((void**)&str);
			ft_memdel((void**)buff);
			ft_error_function(head->tree, "\tANTS NUMBER ERROR.");
		}
	}
	bol = ft_save_rooms_and_edges(index, str, stop, head);
	if (!(head->start) || !(head->end))
		ft_error_function(head->tree, NULL);
	ft_memdel((void**)&str);
	return (bol);
}

/*
** ****************************************************************************
*/

int		ft_len_adj(t_adj *list)
{
	int		len;
	t_adj	*current;

	len = 0;
	current = list;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

/*
** ****************************************************************************
** reads whats the max start can give and the max sink can get
** so that you can know the max-flow the graph can take at each turn.
*/

void	ft_count_bottleneck_edges(t_box *head)
{
	int	p_end;
	int	p_start;

	p_start = ft_len_adj(head->start->adj);
	p_end = ft_len_adj(head->end->adj);
	head->ports = (p_start > p_end) ? p_end : p_start;
}

/*
** ****************************************************************************
** ft_print_all_paths(paths, ret);
*/

int		main(void)
{
	t_box			head;
	int				ret;
	char			*buff;
	t_path			*paths;
	const	char	*error[3] = {"NO ROOMS", "NO EDGES", "NO START/END ROOM"};

	head.tree = NULL;
	head.start = NULL;
	head.end = NULL;
	head.ants_nbr = 0;
	paths = NULL;
	ret = ft_read_input(&head, &buff);
	ft_printf("%s\n\n\n", buff);
	head.vertics_num++;
	if (ret < 2)
		ft_error_function(head.tree, (char*)error[ret]);
	ft_count_bottleneck_edges(&head);
	ret = ft_get_the_max_flow(&head, &paths);
	ft_pass_ants(paths, ret, head.ants_nbr);
	ft_free_tree(head.tree);
	ft_memdel((void**)&buff);
	ft_free_path_group(&paths);
	ft_memdel((void**)&paths);
	return (0);
}

/*
** ****************************************************************************
*/
