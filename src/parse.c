/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:32:05 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/11 23:17:31 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:42:07 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/11 20:21:54 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"
#include <stdbool.h>
#define BUFF_READ 10000
int this_ant = 1;
/*
 ** ****************************************************************************
 */

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

int		ft_next_start(char *str, int *idx, int stop)
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
 */

int	get_ants_num(char *str, int *number_of_ants)
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
 */

int		ft_hundle_rooms(int index, char *str, int stop, t_box *head)
{
	int		start;
	int		bol;
	int		var;
	t_data	data;

	bol = 1;
	data.var = 'M';
	while (index < stop)
	{
		start = ft_next_start(str, &index, stop);
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
		start = ft_next_start(str, &index, stop);
		bol = get_ants_num(str + start, &(head->ants_nbr));
		if (bol == -1)
		{
			ft_memdel((void**)&str);
			ft_memdel((void**)buff);
			ft_error_function(head->tree, "\tANTS NUMBER ERROR.");
		}
	}
	bol = ft_hundle_rooms(index, str, stop, head);
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
 */

int		ft_min(int a, int b)
{
	return ((a > b) ? b : a);
}

/*
 ** ****************************************************************************
 */

void	ft_cnt_ports(t_box *head)
{
	int	p_end;
	int	p_start;

	p_start = ft_len_adj(head->start->adj);
	p_end = ft_len_adj(head->end->adj);
	head->ports = ft_min(p_start, p_end);
}

/*
 ** ****************************************************************************
 */

void		ft_print_ant(int i, char *str)
{
	ft_putchar('L');
	ft_putnbr(i);
	ft_putchar('-');
	ft_putstr(str);
	ft_putchar(' ');
}

/*
 ** ****************************************************************************
 */

int		ft_find_big_path(int maxflow, t_path *paths, int *index)
{
	int	i;
	int	len;
	int min;

	len = 0;
	min = 2147483647;
	i = 0;
	while (i < maxflow)
	{
		if (len < paths[i].len)
			len = paths[i].len;
		i++;
	}
	return (len);
}

/*
 ** ***************************************************************************
 */

void	cout_ants_in_path(int maxflow, t_path *paths, int nbr_of_ants)
{
	int	i;
	int big;
	int div;
	int mod;
	int	min_path;

	div = 0;	
	i = 0;
	min_path = 0;
	big = ft_find_big_path(maxflow, paths, &min_path);
	while (i < maxflow)
	{
		paths[i].path_ant_nbr = big - paths[i].len;
		div = div + paths[i].path_ant_nbr;
		i++;
	}
	div = (nbr_of_ants - div) / maxflow;
	mod = (nbr_of_ants - div) % maxflow;
	i = 0;
	while (i < maxflow)
	{
		paths[i].path_ant_nbr = paths[i].path_ant_nbr + div;
		if (mod > 0)
			paths[i].path_ant_nbr++;
		i++;
	}
}

/*
 ** *****************************************************************************
 *

int		ft_in_this_room(t_list_simple *path, int ant, int nbr_of_ants)
{
	int i;

	i = 0;
	if (path->next && path->next->position == 0 && path->position != 0)
	{
		path->next->position = path->position;
		ft_print_ant(path->position, path->next->content, nbr_of_ants);
		path->position = 0;	
		i = 1;
	}
	else if (path->next && path->next->position != 0 && path->position != 0)
		i = ft_in_this_room(path->next, path->position, nbr_of_ants);
	if (ant != -1)
	{
		path->position = ant;
		ft_print_ant(path->position, path->content, nbr_of_ants);
		i = 1;
	}
	else
		path->position = 0;
	return (i);
}

*
 ** ***************************************************************************
 */

int		ft_move_ants(t_list_simple *path, int nbr_of_ants)
{
	int		temp1;
	int		temp2;
	int		ret;

	ret = 0;
	temp2 = 0;
	while (path && path->position == 0)
		path = path->next;
	if(path)
	{
		temp1 = path->position;
		path->position = 0;
		path = path->next;
		ret++;
	}
	while (path)
	{
		temp2 = path->position;
		path->position = temp1;
		temp1 = temp2;
		if (path->position != 0)
			ft_print_ant(path->position, path->content);
		path = path->next;
	}
	return (ret);
}

/*
 ** ***************************************************************************
 */

void	ft_init_path(int ant_nbr, t_path *paths, int i)
{
			paths[i].list->position = ant_nbr;
			paths[i].path_ant_nbr--;
}

/*
 ** ***************************************************************************
*/

void	ft_pass_ants(t_path *paths, int nb_paths, int nbr_of_ants)
{
	int	i;
	int	i_move;
	int	ant_nbr;

	i_move = -1;
	ant_nbr = 0;
	cout_ants_in_path(nb_paths, paths, nbr_of_ants);
	while (i_move != 0)
	{
		i = 0;
		i_move = -1;
		while (i < nb_paths)
		{
			if (ant_nbr > 0)
				i_move = ft_move_ants(paths[i].list, nbr_of_ants);
			if (paths[i].path_ant_nbr > 0)
			{
				ant_nbr = ant_nbr + 1;
				i_move = 1;
				ft_init_path(ant_nbr, paths, i);
				ft_print_ant(paths[i].list->position, paths[i].list->content);
			}
			i++;
		}
		ft_putchar('\n');
	}
}

/*
 ** *****************************************************************************
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

	ret = ft_read_input(&head, &buff);
	head.vertics_num++;
	if (ret < 2)
		ft_error_function(head.tree, (char*)error[ret]);
	ft_cnt_ports(&head);
	ret = ft_get_the_max_flow(&head, &paths);
	ft_pass_ants(paths, ret, head.ants_nbr);
	ft_print_all_paths(paths, ret);
	ft_free_tree(head.tree);
	ft_memdel((void**)&buff);
	ft_simple_lstdel(&(paths->list));
	ft_memdel((void**)&paths);
	return (0);
}

/*
 ** ****************************************************************************
 */
