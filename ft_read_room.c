/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:41:51 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/28 12:53:10 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_read_room(t_stc node, char *line)
{
	int	i;
	char	str;

	i = 0;
	if (line[0] != 'L' && line[0] != '#')
	{
		while (line[i] != ' ')
			i++;
		str = ft_strndup(line, i);
		//test if str exist or not and find best place for it and put it else return 0
		//ft_strdel(&str);
		i++;
		if (!ft_check_nbr(line, i))
		{
			ft_strdel(&line);
			return (0);
		}
		node->tab_rooms[hash_nb]->coord_x = ft_atoi(line + i);
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		i++;
		if (!ft_check_nbr(line, i))
		{
			ft_strdel(&line);
			return (0);
		}
		node->rooms[hash_nb]->coord_y = ft_atoi(line + i);
		return (1);
	}
	else
		return (0);
}
