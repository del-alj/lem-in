/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:35 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/08 01:01:20 by mzaboub          ###   ########.fr       */
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

	if(u->taken == 0)
		return (1);
	if(u->taken == 1 && edge->cap == 2)
		return (1);
	if (u->taken == 1 && get_edge_cap(prev, u) == 2)
		return (1);
	return (0);
}

/*
**	***************************************************************************
*/

int		dfs(t_avl *prev, t_avl *u, t_avl *v, int flow)
{
	t_adj	*adj;
	int		valid_flow;
	int i = 0;

	if (flow <= 0)
	{
		ft_printf("flow is zeeeero \n");
		exit(0);
	}
	if (u->id == v->id)
		return (1);
	adj = u->adj;
	while (adj != NULL)
	{
		if ((adj->cap > 0) && (u->level + 1 == adj->edge->level) && \
				(can_i_pass(prev, u, adj) == 1))
		{
			valid_flow = dfs(u, adj->edge, v, adj->cap + 1);
			if (valid_flow > 0)
			{
				if (u->level != 0 && u->id != v->id)
					u->taken = 1;
				adj->cap -= valid_flow;
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

int		ft_get_the_max_flow(t_box *head, t_path **paths)
{
	int ret;
	int graph_flow;
	int	iter = 1;
	int	score = 2147483647;

	graph_flow = 0;
	while (bfs(head, head->start, head->end) != -1)
	{
		while ((ret = dfs(NULL, head->start, head->end, 1)) > 0)
			graph_flow += ret;
		if (!(ft_score(head, graph_flow, &score, paths)))
		{
			--graph_flow; // in this case, we'll ignore the last path we added
			break ;
		}
		ft_origin_bfs(head->start, head->end);
	}
	return (graph_flow);
}

/*
**	***************************************************************************
*/
