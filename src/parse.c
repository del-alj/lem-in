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

/*
** ****************************************************************************
*/

static	void	ft_read_all_file(char **str, int *length, char **backup_buff)
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

int				ft_update_next_start(char *str, int *idx, int stop)
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

static	int		get_ants_num(char *str, int *number_of_ants)
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
** read all the input at once and keep it in two separate buffers
** escap the comments at start tell you find the ants number
*/

int				ft_read_input(t_box *head, char **buff)
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
