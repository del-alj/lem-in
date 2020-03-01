/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_origin_bfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:59:37 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/01 11:55:11 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_origin_bfs(t_avl *start, t_avl *end)
{
	t_queue	*q;
	t_adj	*u;
	int		level;
	int		cnt = -1;

	level = 1;
	q = ft_init_queue(start);
	u = start->adj;
	while (u)
	{
		if (ft_is_not_visited(q->list, u->edge) && u->cap != 0)
		{
			q->front->next = (t_adj*)malloc(sizeof(t_adj));
			q->front->next->edge = u->edge;
			if (q->front->next->edge->level == 0)
				q->front->next->edge->level = q->rear->edge->level + 1;
			q->front->next->next = NULL;
			q->front = q->front->next;
			if (q->front->edge->id == end->id)
				cnt = 1;
		}
		u = u->next;
		if (!u)
		{
			q->rear = q->rear->next;
			if (!q->rear || (q->rear->edge->id == end->id))
				return (cnt);
			u = q->rear->edge->adj;
		}
	}
	return (0);
}
