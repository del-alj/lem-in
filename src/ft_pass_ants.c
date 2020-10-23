/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:25:13 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/12 21:30:27 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

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
	int	big;
	int	div;
	int	mod;
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
	mod = (nbr_of_ants - div) % maxflow;
	div = (nbr_of_ants - div) / maxflow;
	i = -1;
	while (++i < maxflow)
	{
		paths[i].path_ant_nbr = paths[i].path_ant_nbr + div;
		if (mod-- > 0)
			paths[i].path_ant_nbr++;
	}
}

/*
** *****************************************************************************
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
	if (path && path->position != 0 && path->next)
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
	ft_print_ant(paths[i].list->position, paths[i].list->content);
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
			}
			i++;
		}
			ft_putchar('\n');
	}
}
