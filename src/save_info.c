/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:15:16 by mzaboub           #+#    #+#             */
/*   Updated: 2020/11/03 10:15:17 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

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
** ****************************************************************************
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
** ****************************************************************************
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
