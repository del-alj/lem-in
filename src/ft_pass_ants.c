/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:25:13 by del-alj           #+#    #+#             */
/*   Updated: 2020/11/02 09:09:00 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** *****************************************************************************
** this func goes recursively to the end of the path, then starts printing
** in reverse (from the last vert in the path).
*/

static	void	ft_move_and_print(t_list_simple *path, \
									int nbr_of_ants, \
									int temp1)
{
	int	temp2;

	temp2 = 0;
	if (path)
	{
		temp2 = path->position;
		path->position = temp1;
		temp1 = temp2;
		ft_move_and_print(path->next, nbr_of_ants, temp1);
		if (path->position != 0)
			ft_print_ant(path->position, path->content);
	}
}

/*
** *****************************************************************************
*/

static	int		ft_move_ants(t_list_simple *path, int nbr_of_ants)
{
	int		temp;
	int		ret;

	ret = 0;
	temp = 0;
	while (path && path->position == 0)
		path = path->next;
	if (path && path->position != 0 && path->next)
	{
		temp = path->position;
		path->position = 0;
		path = path->next;
		ret++;
	}
	ft_move_and_print(path, nbr_of_ants, temp);
	return (ret);
}

/*
** ***************************************************************************
** this fill's the first vertics in each path with the apropriate ant.
*/

static	void	ft_init_path(int ant_nbr, t_path *paths, int i)
{
	paths[i].list->position = ant_nbr;
	paths[i].path_ant_nbr--;
	ft_print_ant(paths[i].list->position, paths[i].list->content);
}

/*
** ***************************************************************************
*/

void			ft_pass_ants(t_path *paths, int nb_paths, int nbr_of_ants)
{
	int	i;
	int	i_move;
	int	ant_nbr;

	i_move = -1;
	ant_nbr = 0;
	count_ants_in_path(nb_paths, paths, nbr_of_ants);
	while (i_move != 0)
	{
		i = 0;
		i_move = 0;
		while (i < nb_paths)
		{
			if (ant_nbr > 0)
				i_move += ft_move_ants(paths[i].list, nbr_of_ants);
			if (paths[i].path_ant_nbr > 0)
			{
				ant_nbr = ant_nbr + 1;
				i_move += 1;
				ft_init_path(ant_nbr, paths, i);
			}
			i++;
		}
		ft_putchar('\n');
	}
}
