/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:42:07 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/20 13:30:01 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"
#include <stdbool.h>
#define BUFF_READ 10000

/*
** ****************************************************************************
*/
int	ft_get_room_info(char *str, int i, t_data *data)
{
	str[i] = '\0';
	data->room = str;
	str = str + i + 1;
	data->x = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		++str; 
	if (ft_isspace((int)*str) != 1)// there is something different then a num
		return (-1);
	++str;// fout l'espace
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

int	ft_get_edge_info(char *str, int i, t_data *data)
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

int	ft_check_line(char *str, t_data *data, t_box *head)
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
		return (0);
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
//ft_printf("{green} start = %d, stop = %d; {eoc}\n", start, *stop);
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
	/*
	while ((ret = read(0, buff, BUFF_READ)) > 0)
	{
		buff[ret] = 0;
		temp = ft_strjoin(*str, buff);
		if (!temp)
			exit(0);
		ft_memdel((void**)str);
		*str = temp;
		*length += ret;
		if (ret < BUFF_READ)
			break;
	}
	*/
}

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
	*number_of_ants = ft_atoi(str);
	return (1);
}

/*
** ****************************************************************************
*/

int		ft_read_input(t_box *head)
{
	char *str;
	int index;
	int s;
	int var;
	int bol;
	int stop;
	int	number_of_ants;
	t_data data;

	s = 0;
	var = 0;
	bol = 0;
	index = 0;
	data.var = 'M';
	number_of_ants = 0;
	ft_read_all_file(&str, &stop);
	while(index < stop)
	{
		s = ft_next_start(str, &index, stop);
		if (bol == 0)// about first line info
		{
			var = get_ants_num(str + s, &number_of_ants);
			if (var == -1)
			{
				ft_printf("{red}\tANTS NUMBER ERROR.{eoc}\n");
				ft_memdel((void**)&str);
				exit(0);
			}
			else if (var == 1)
				bol = 1;
		}
		else
		{
			var = ft_check_line(str + s, &data, head);
			if ((data.var == 'S' && head->start) || (data.var == 'E' && head->end))
				ft_error_function(head->tree);
			if (var == -1)
			{
				ft_printf("{red}\tERROR in LINE INFO.{eoc}\n");
				ft_memdel((void**)&str);
				exit(0);
			}
			else if (var == 1)
			{
				if (bol == 2)
				{
					ft_printf("{red}\tERROR in ROOM DEFINED AFTER AN EDGE.{eoc}\n");
					ft_memdel((void**)&str);
					exit(0);
				}
				if ((head->tree) != NULL)
					ft_insert_node(&(head->tree), data, head); //ft_insert_node(head, data);
				else
				{
					(head->tree) = ft_new_node(data);
					ft_if_start_end(head->tree, data, head);
				}
				data.var = 'M';
			}
			else if (var == 2)
			{
				//ft_add_edge(head, data.room, data.adj_room);
				ft_add_edge(&(head->tree), data.room, data.adj_room);
				bol = 2;
				
			}
		}
	}
	if (!(head->start) || !(head->end))
		ft_error_function(head->tree);
	ft_memdel((void**)&str);
	return (bol);
}

/*
** ****************************************************************************
** 
** void	ft_insert_node(t_avl **tree, t_data data)
** {
** ft_printf("{green}	insert room {eoc}\t\t");
** ft_printf("name : %s;\tx:%d;\ty:%d;var:%c;\n",data.room, data.x, data.y, data.var);
** }
** 
** void	ft_add_edge(t_avl **tree, char *room, char *adj_room)
** {
** ft_printf("{blue}	insert edge {eoc}\t\t");
** ft_printf("room : %s;\tadj_room:%s;\n", room, adj_room);
** }
*/

int	main(void)
{
	t_box	head;
	int ret;

	head.tree = NULL;
	head.start = NULL;
	head.end = NULL;
	head.ants_nbr = 0;

	ret = ft_read_input(&head);
	char *error[3] = {"NO ROOMS", "NO EDGES", "NO START/END ROOM"};
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

