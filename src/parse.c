/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:42:07 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/18 11:09:53 by mzaboub          ###   ########.fr       */
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
		return (0);
	++str;// fout l'espace
	data->y = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		++str; 
	if (*str != '\0')
		return (0);
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
		return (0);
	data->adj_room = str;
	return (2);
}

/*
** ---------------------------------------------------------------------------
*/

int	ft_check_line(char *str, t_data *data)
{
	int i;

	if (str[0] == '#')
	{
		if (ft_strnequ(str, "##start", 7) == 1)
		{
		//	ft_printf("{red}start{eoc}\n");
			data->var = 'S';
		}
		else if (ft_strnequ(str, "##end", 5) == 1)
		{
	//		ft_printf("{red}end{eoc}\n");
			data->var = 'E';
		}
		return (-1);
	}
	else
	{
		i = 0;
		while ((str[i]) && (ft_isspace(str[i]) != 1) && (str[i] != '-'))
			i++;
		if (str[i] && str[i] != '-')// this is a room 
		{
			return (ft_get_room_info(str, i, data));
		}
		else if (str[i] && str[i] == '-')// this is an edge
		{
			return (ft_get_edge_info(str, i, data));
		}
	}
	return (0);
}

/*
** ****************************************************************************
*/
int	ft_read_another_part(char **str, int *idx, int *stop)
{
	char *end;
	char *temp;
	int		start;
	int		ret;

	start = *idx;
	//ft_printf("{green} start = %d, stop = %d; {eoc}\n", start, *stop);
	while ((*str)[*idx] && (*str)[*idx] != '\n')
		(*idx)++;
	if ((*str)[*idx] == '\n')
		return (start);
	if(!(end = (char*)ft_memalloc(BUFF_READ + 1)))
	{
		// you should free here
		ft_printf("ERROR"); return (false);
	}
	ret = read(0, end, BUFF_READ);
	end[ret] = 0;
	temp = ft_strjoin((*str) + start, end);
	ft_memdel((void**)str);
	ft_memdel((void**)&end);
	*str = temp;
	*stop = *stop - start + ret;
	*idx = 0;
	if (*stop == 0)
		return (-1);
	return (ft_read_another_part(str, idx, stop));
}

bool	ft_read_input(t_avl **tree)
{
	char *str;
	int index;
	int s;
	int var;
	int bol;
	int stop;
	t_data data;

	index = 0;
	s = 0;
	bol = 0;
	var = 'M';

	if(!(str = (char*)ft_memalloc(BUFF_READ + 1)))
	{
		ft_printf("ERROR"); return (false);
	}
	stop = read(0, str, BUFF_READ);
	str[stop] = 0;
	while(index <= stop)
	{
 		s = ft_read_another_part(&str, &index, &stop);
		if (s == -1)
			break;
		//ft_printf("{red} start :%d ; index : %d; stop : %d; {eoc}\n", s, index, stop);
		str[index] = '\0';
		//ft_printf("{magenta} str[%d] : [%s] {eoc}\n", s, str+s);
		if (s == 0 && (bol == 0))
		{
			int number_of_rooms = ft_atoi(str);
			ft_printf("{yellow} numOf rooms == %d {eoc}\n", number_of_rooms);
			bol = 1;
		}
		else
		{
			var = ft_check_line(str + s, &data);
			if (var == 0 || ((var == 1) && (bol == 2)))
			{
				ft_printf("{red} ERROR {eoc}\n");
				ft_memdel((void**)&str);
				return (0);
			}
			if (var == 1)
			{
				ft_insert_node(tree, data);
				data.var = 'M';
			}
			else if (var == 2)
			{
				ft_add_edge(tree, data.room, data.adj_room);
				bol = 2;
			}
		}
		index++;
	}
	ft_memdel((void**)&str);
	return (true);
}

/*
** ****************************************************************************
*/

void	ft_insert_node(t_avl **tree, t_data data)
{
	ft_printf("{green}	insert room {eoc}\t\t");
	ft_printf("name : %s;\tx:%d;\ty:%d;var:%c;\n",data.room, data.x, data.y, data.var);
}

void	ft_add_edge(t_avl **tree, char *room, char *adj_room)
{
	ft_printf("{blue}	insert edge {eoc}\t\t");
	ft_printf("room : %s;\tadj_room:%s;\n", room, adj_room);
}

int	main(void)
{
	t_avl *tree;
	t_data data;
	char *line;
	int nbr = 10;
	int ret;

	tree = NULL;
	/*
	while (nbr--)
	{
		get_next_line(0, &line);
		ret = ft_check_room(line, &data);
		if (ret == 0)
			ft_printf("	ret = {red} %d {eoc}\n", ret);
		else if (ret == 1)
		{
			ft_printf("	ret == %d, name == %s;\n", ret, data.room);
			ft_printf("	x == %d, y == %d, var = %c;\n", data.x, data.y, data.var);
			// room_insert()
			data.var = 'M';
		}
		else if (ret == 2)
		{
			ft_printf("	ret == %d, name1 == %s, name2 == %s;\n", ret, data.room, data.adj_room);
			// baqi xxx
		}
		else
				ft_printf("	ret = {red} %d {eoc}\n", ret);
	}
	*/
	ft_read_input(&tree);
	return (0);
}

/*
** ****************************************************************************
*/

