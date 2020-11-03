/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:35:33 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/12 21:13:38 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** *****************************************************************************
*/

static	int		ft_find_big_path(int maxflow, t_path *paths, int *index)
{
	int	i;
	int	len;

	len = 0;
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
** this counts how many ants will pass by each of the paths
*/

void			count_ants_in_path(int maxflow, t_path *paths, int nbr_of_ants)
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

void			ft_print_ant(int i, char *str)
{
	ft_putchar('L');
	ft_putnbr(i);
	ft_putchar('-');
	ft_putstr(str);
	ft_putchar(' ');
}
