/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_origin_bfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:59:37 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/02 21:36:37 by mzaboub          ###   ########.fr       */
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
		if (ft_is_not_visited(q->head, u->edge))
		{
			q->front->next = (t_adj*)malloc(sizeof(t_adj));
			q->front->next->edge = u->edge;
			q->front->next->edge->level = 0;
			q->front->next->next = NULL;
			q->front = q->front->next;
			if (q->front->edge->id == end->id)
				cnt = 1;
		}
		u = u->next;
		if (!u)
		{
			q->rear = q->rear->next;
			if (q->rear == NULL)
				return (cnt);
			u = q->rear->edge->adj;
		}
	}
	return (cnt);
}
