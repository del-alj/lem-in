/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:35 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/12 20:43:16 by mzaboub          ###   ########.fr       */
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
		ptr->cap += flow;
}

/*
**	***************************************************************************
*/

int		get_edge_cap(t_avl *u, t_avl *v)
{
	t_adj *ptr;

	if (u == NULL)
		return (1);
	ptr = u->adj;
	while (ptr)
	{
		if (ptr->edge->id == v->id)
			return (ptr->cap);
		ptr = ptr->next;
	}
	return (0);
}

/*
**	***************************************************************************
*/

int		can_i_pass(t_avl *prev, t_avl *u, t_adj *edge)
{
	if (u->taken == 0)
		return (1);
	if (u->taken == 1 && edge->cap == 2)
		return (1);
	if (u->taken == 1 && get_edge_cap(prev, u) == 2)
		return (1);
	return (0);
}

/*
**	***************************************************************************
*/

int		dfs(t_avl *prev, t_avl *u, t_avl *v, int *level)
{
	int		i;
	t_adj	*adj;
	int		valid_flow;

	if (u->id == v->id)
		return (1);
	i = 0;
	adj = u->adj;
	while (adj != NULL)
	{
		if ((adj->cap > 0) && (level[u->id] + 1 == level[adj->edge->id]) && \
				(can_i_pass(prev, u, adj) == 1) && \
				((valid_flow = dfs(u, adj->edge, v, level)) > 0))
		{
			if (level[u->id] != 0 && u->id != v->id)
				u->taken = 1;
			adj->cap -= valid_flow;
			ft_increase_capacity(adj->edge->adj, u, valid_flow);
			return (valid_flow);
		}
		adj = adj->next;
	}
	return (0);
}

/*
**	***************************************************************************
**	tmp[0] = ret;
**  tmp[1] = tmp;
*/

int		ft_get_the_max_flow(t_box *head, t_path **paths)
{
	int			tmp[2];
	t_bfs_data	dt;
	int			graph_flow;
	int			score;

	graph_flow = 0;
	score = 2147483647;
	if (((dt.level = ft_memalloc((head->vertics_num) * sizeof(int))) == NULL) ||
	((dt.visited = ft_memalloc((head->vertics_num + 1) * sizeof(int))) == NULL))
		exit(EXIT_FAILURE);
	while (bfs(head, head->start, &dt) != -1)
	{
		tmp[1] = graph_flow;
		while ((tmp[0] = dfs(NULL, head->start, head->end, dt.level)) > 0)
			graph_flow += tmp[0];
		if (0 == ft_score(head, graph_flow, &score, paths))
		{
			graph_flow -= (graph_flow - tmp[1]);
			break ;
		}
		ft_memset(dt.level, 0, head->vertics_num * sizeof(int));
		ft_memset(dt.visited, 0, (head->vertics_num + 1) * sizeof(int));
	}
//	ft_free_data(dt);
	return (graph_flow);
}

/*
**	***************************************************************************
*/

void	ft_free_data(t_bfs_data dt)
{
	ft_memdel((void**)&dt.visited);
	ft_memdel((void**)&dt.level);
	if (dt.q != NULL)
		ft_free_queue(&dt.q);
}

void	ft_free_queue(t_queue **q)
{
	t_adj	*head;
	t_adj	*nxt;

	if (q && *q)
	{
		head = (*q)->head;
		while (head != NULL)
		{
			nxt = head->next;
			ft_memdel((void**)&head);
			head = nxt;
		}
		ft_memdel((void**)q);
		*q = NULL;
	}
}
