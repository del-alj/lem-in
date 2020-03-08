/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:58 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/08 21:38:40 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
**	***************************************************************************
*/

t_path  *ft_make_group(t_box *head, int nb_path, int *score)
{
	int     i;
	t_adj	*ptr;
	t_path  *paths;
	
	i = 0;
	paths = NULL;
	if(!(paths = (t_path*)ft_memalloc((nb_path)* sizeof(t_path))))
		return (0);
	ptr = head->start->adj;
	while (i < nb_path && ptr)
	{
		while (ptr->cap != 0)
			ptr = ptr->next;
		paths[i].list = NULL;
		paths[i].len = ft_get_path(ptr->edge, head->end, paths + i);
		if ((paths + i == NULL) || (paths[i].len == 0))
			break;
		i++;
		ptr = ptr->next;
	}
	return (paths);
}

/*
**	***************************************************************************
*/

int	ft_score(t_box *head, int nb_path, int *score, t_path **paths)
{
	t_path	*group;
	int		new_score;
	int		indx;

	new_score = 0;
	group = NULL;
	indx = 0;
	group = ft_make_group(head, nb_path, score);
	while ((indx < nb_path) && (group + indx != NULL))
	{
		new_score = new_score + (group[indx].len);// numbre of edges
		indx++;
	}
	new_score = ((new_score + head->ants_nbr) / nb_path) - 1;
	if (new_score < (*score))
	{	
	//	ft_printf("old score == %d, new_score = %d;\n", *score, new_score);
		(*score) = new_score;
		//free *path here;
		*paths = group;
		return (1);
	}
	return (0);
}

/*
**	***************************************************************************
*/

int		ft_get_path(t_avl *u, t_avl *v, t_path *path)
{
	t_adj	*adj;
	int		valid_flow;

	if (u->id == v->id)
	{
		ft_add_to_path(path, u->name);
		return (1);
	}
	adj = u->adj;
	while (adj != NULL)
	{
		if (adj->cap == 0)
		{
			valid_flow = ft_get_path(adj->edge, v, path);
			if (valid_flow > 0)
			{
				ft_add_to_path(path, u->name);
				return (valid_flow + 1);
			}
			valid_flow = 0;// in case we didn't find a path by recursive;
		}
		adj = adj->next;
	}
	return (0);
}

/*
**	***************************************************************************
*/

void	ft_add_to_path(t_path *path, char *name)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		exit(0);
	tmp->content = ft_strdup(name);
	tmp->next = path->list;
	path->list = tmp;
}

/*
**	***************************************************************************
*/

