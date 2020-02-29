/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:35 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/29 14:42:19 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
**	***************************************************************************
*/

void	ft_increase_capacity(t_adj *edge, t_avl *v, int flow)
{
	t_adj	*ptr;

	ptr = edge;
	while (ptr && (ptr->edge->id != v->id))
		ptr = ptr->next;
	if (ptr)
		ptr->cap -= flow;
}

/*
**	***************************************************************************
*/

int		dfs(t_avl *u, t_avl *v, int flow)
{
	t_adj	*edge;
	int		valid_flow;

	if (u == v)
		return (flow);
	edge = u->adj;
	while (edge != NULL)
	{
		// you should check if you can go to this vertics.
		// if that vertics is taken, check if you gonna do correction
		if ((edge->cap > 0) && (u->level == (edge->edge->level - 1)))
		{
			valid_flow = dfs(edge->edge, v, MIN_OF2(edge->cap, flow));
			if (valid_flow > 0)
			{
				edge->cap -= valid_flow;
				u->taken = (++(u->taken) % 2);
				ft_increase_capacity(edge->edge->adj, u, valid_flow);
				return (valid_flow);
			}
		}
		edge = edge->next;
	}
	return (0);
}

/*
**	***************************************************************************
*/

int		ft_get_the_max_flow(t_box *head)
{
	int ret;
	int graph_flow;

	graph_flow = 0;
	while (bfs() != -1)
	{
		while ((ret = dfs(head->start, head->end, INT_MAX)) > 0)
			graph_flow += ret;
	}
	return (graph_flow);
}

/*
**	***************************************************************************
*/

int		ft_get_path(t_avl *u, t_avl *v, t_path **path)
{
	t_adj	*edge;
	t_path	*tmp;
	int		valid_flow;

	if (u == v)
	{
		if(!(tmp = (t_path*)ft_memalloc(sizeof(t_path))))
			exit(0);
		tmp->vert_name = ft_strdup(u->name);
		tmp->next = *path;
		tmp->len = 1;
		*path = tmp;
		return (1);
	}
	edge = u->adj;
	while (edge != NULL)
	{
		if (edge->cap == 0)
		{
			valid_flow = ft_get_path(edge->edge, v, path);
			if (valid_flow > 0)
			{
				edge->cap += valid_flow;
				tmp->vert_name = ft_strdup(u->name);
				tmp->next = *path;
				tmp->len = (*path)->len + 1;
				*path = tmp;
				return (valid_flow);
			}
			valid_flow = 0;// in case we didn't find a path by recursive;
		}
		edge = edge->next;
	}
	return (0);
}

/*
**	***************************************************************************
*/

t_path	**ft_all_paths(t_box *head, int	*maxflow)
{
	t_path	**paths;
	int		g_flow;
	int		i;

	// explore all paths and marking them by '0'
	g_flow = ft_get_the_max_flow(head);

	// allocate a table for all the paths
	if(!(paths = ft_memalloc((g_flow + 1)* sizeof(t_path))))
		exit(0);
	paths[g_flow] = NULL;	
	i = 0;
	// traversing the graph for one last time, to get all paths
	while (i < g_flow )
	{
		// getting the name a paths (linked list if vertics names)
		if ((paths[i]->len = ft_get_path(head->start, head->end, paths + i)) == 0)
			break;
		i++;
	}
	*maxflow = g_flow;
	return (paths);
}

/*
**	***************************************************************************
*/
