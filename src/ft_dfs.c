/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:35 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/29 16:41:11 by mzaboub          ###   ########.fr       */
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
	t_adj	*adj;
	int		valid_flow;

	if (u->id == v->id)
		return (flow);
	adj = u->adj;
	while (adj != NULL)
	{
		// you should check if you can go to this vertics.
		// if that vertics is taken, check if you gonna do correction
		if ((adj->cap > 0) && ((u->level == adj->edge->level - 1) || (adj->edge->id == v->id)))
		{
			valid_flow = dfs(adj->edge, v, MIN_OF2(adj->cap, flow));
			if (valid_flow > 0)
			{
				adj->cap -= valid_flow;
				u->taken = (++(u->taken) % 2);
				ft_increase_capacity(adj->edge->adj, u, valid_flow);
				return (valid_flow);
			}
		}
		adj = adj->next;
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
	while (ft_bfs(head->start, head->end) != -1)
	{
		while ((ret = dfs(head->start, head->end, INT_MAX)) > 0)
		{
			graph_flow += ret;
			//ft_print_link(head->tree, 's');
		}
	}
	return (graph_flow);
}

/*
**	***************************************************************************
*/

int		ft_get_path(t_avl *u, t_avl *v, t_path **path)
{
	t_adj	*adj;
	t_path	*tmp;

	tmp = NULL;
	int		valid_flow;

	if (u->id == v->id)
	{
		if(!(tmp = (t_path*)ft_memalloc(sizeof(t_path))))
			exit(0);
		tmp->vert_name = ft_strdup(u->name);
		tmp->next = NULL;
		tmp->len = 1;
		*path = tmp;
		return (1);
	}
	adj = u->adj;
	while (adj != NULL)
	{
		if (adj->cap == 0 && ((u->level == adj->edge->level - 1) || (adj->edge->id == v->id)))
		{
			valid_flow = ft_get_path(adj->edge, v, path);
			if (valid_flow > 0)
			{
				adj->cap += valid_flow;
				if(!(tmp = (t_path*)ft_memalloc(sizeof(t_path))))
					exit(0);
				tmp->vert_name = ft_strdup(u->name);
				tmp->next = *path;
				tmp->len = (*path)->len + 1;
				*path = tmp;
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

t_path	**ft_all_paths(t_box *head, int	*maxflow)
{
	t_path	**paths;
	int		g_flow;
	int		i;

	// explore all paths and marking them by '0'
	//ft_print_link(head->tree, 'p');
	g_flow = ft_get_the_max_flow(head);
	//ft_print_link(head->tree, 'p');
	// allocate a table for all the paths
	if(!(paths = ft_memalloc((g_flow + 1)* sizeof(t_path*))))
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
