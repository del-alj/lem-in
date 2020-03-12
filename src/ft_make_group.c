/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:58 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/12 08:11:40 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
**	***************************************************************************
*/

t_path	*ft_make_group(t_box *head, int nb_path, int *score)
{
	int		i;
	t_adj	*ptr;
	t_path	*paths;

	i = 0;
	paths = NULL;
	if (!(paths = (t_path*)ft_memalloc((nb_path + 1) * sizeof(t_path))))
		exit(EXIT_FAILURE);
	ptr = head->start->adj;
	while (i < nb_path && ptr)
	{
		while (ptr->cap != 0)
			ptr = ptr->next;
		paths[i].list = NULL;
		paths[i].len = ft_get_path(ptr->edge, head->end, paths + i);
		if ((paths + i == NULL) || (paths[i].len == 0))
			break ;
		i++;
		ptr = ptr->next;
	}
	while (i <= nb_path)
		paths[i++].list = NULL;
	return (paths);
}

/*
**	***************************************************************************
*/

int		ft_score(t_box *head, int nb_path, int *score, t_path **paths)
{
	int		indx;
	t_path	*group;
	int		new_score;

	indx = 0;
	group = NULL;
	new_score = 0;
	group = ft_make_group(head, nb_path, score);
	while ((indx < nb_path) && (group + indx != NULL))
	{
		new_score = new_score + (group[indx].len);
		++indx;
	}
	new_score = ((new_score + head->ants_nbr) / nb_path) - 1;
	if (new_score < (*score))
	{
	//	ft_free_path_group(paths);
		*paths = group;
		(*score) = new_score;
		return (1);
	}
//	ft_free_path_group(&group);
	return (0);
}

void	ft_free_path_group(t_path **paths_ptr)
{
	int				i;
	t_list_simple	*lst;
	t_list_simple	*nxt;
	t_path			*paths;

	paths = *paths_ptr;
	if (paths_ptr && paths)
	{
		i = -1;
		while (paths[++i].list != NULL)
		{
			lst = paths[i].list;
			while (lst != NULL)
			{
				nxt = lst->next;
				if (lst->content)
					free(lst->content);
				free(lst);
				lst = nxt;
			}
		}
		if (*paths_ptr)
			free(*paths_ptr);
		*paths_ptr = NULL;
	}
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
	t_list_simple	*tmp;

	if (!(tmp = (t_list_simple*)malloc(sizeof(t_list))))
		exit(0);
	tmp->content = ft_strdup(name);
	tmp->position = 0;
	tmp->next = path->list;
	path->list = tmp;
}

/*
**	***************************************************************************
*/
