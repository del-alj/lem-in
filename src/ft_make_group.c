/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:58 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/07 19:54:45 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

t_path  **ft_make_group(t_box *head, int nb_path, int *score)
{
	int     i;
	int		len;
	t_path  **paths;
	
	paths = NULL;


	if(!(paths = ft_memalloc((nb_path + 1)* sizeof(t_path*))))
		return (0);
	paths[nb_path] = NULL;
	i = 0;
	while (i < nb_path)
	{
		len = ft_get_path(head->start, head->end, &paths[i]);
		if (!paths[i])
			break;
		if((paths[i]->len = len) == 0)
			break;
		i++;
	}
	return (paths);
}

int	ft_score(t_box *head, int nb_path, int *score, t_path ***path)
{
	t_path	**group = NULL;
	int		i;
	int indx = 0;
	i = 0;
	group = ft_make_group(head, nb_path, score);
	while (indx < nb_path && group[indx])
	{
		i = i + (group[indx]->len) - 1;
		indx++;
	}
	i = (i + head->ants_nbr) / nb_path - 1;
	if (i < (*score))
	{	
		(*score) = i;
		*path = group;
		return (1);
	}
	return (0);
}
