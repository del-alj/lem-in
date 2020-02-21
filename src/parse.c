/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:42:07 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/20 14:32:27 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"
#include <stdbool.h>
#define BUFF_READ 10000

/*
** ****************************************************************************
*/

int		ft_get_room_info(char *str, int i, t_data *data)
{
	str[i] = '\0';
	data->room = str;
	str = str + i + 1;
	data->x = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		++str;
	if (ft_isspace((int)*str) != 1)
		return (-1);
	++str;
	data->y = ft_atoi(str);
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

void	ft_read_all_file(char **str, int *length)
{
	char	buff[BUFF_READ + 1];
	char	*temp;
	int		ret;

	*str = (char*)ft_memalloc(BUFF_READ + 1);
	if (!str)
		exit(0);
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
** ***********************************5*****************************************
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
	*number_of_ants = ft_atoi(str);
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
		ft_error_function(head->tree, \
				"{red}\tERROR in ROOM DEFINED AFTER AN EDGE.{eoc}");
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
			ft_error_function(head->tree, "ERROR in LINE INFO");
		var = ft_check_line(str + start, &data, head);
		if (var == -1 || (data.var == 'S' && head->start) || \
						(data.var == 'E' && head->end))
		{
			ft_memdel((void**)&str);
			ft_error_function(head->tree, "{red}\tERROR in LINE INFO.{eoc}");
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

int		ft_read_input(t_box *head)
{
	char	*str;
	int		index;
	int		start;
	int		bol;
	int		stop;

	bol = 0;
	index = 0;
	ft_read_all_file(&str, &stop);
	while (bol == 0)
	{
		start = ft_next_start(str, &index, stop);
		bol = get_ants_num(str + start, &(head->ants_nbr));
		if (bol == -1)
		{
			ft_memdel((void**)&str);
			ft_error_function(head->tree, "{red}\tANTS NUMBER ERROR.{eoc}");
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

int		main(void)
{
	t_box			head;
	int				ret;
	const	char	*error[3] = {"NO ROOMS", "NO EDGES", "NO START/END ROOM"};

	head.tree = NULL;
	head.start = NULL;
	head.end = NULL;
	head.ants_nbr = 0;
	ret = ft_read_input(&head);
	if (ret < 2)
	{
		ft_printf("{red}\tERROR %s;{eoc}\n", error[ret]);
		return (0);
	}
	ft_print_link(head.tree, 'o');
	return (0);
}

/*
** ****************************************************************************
*/
