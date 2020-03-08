/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:02:25 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/08 23:24:00 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_is_not_visited(t_adj *list, t_avl *room)
{
	t_adj	*current;

	current = list;
	while (current)
	{
		if (current->edge->id == room->id)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
** ***************************************************************************
*/

t_queue	*ft_init_queue(t_avl *start)
{
	t_queue	*q;

	q = (t_queue*)malloc(sizeof(t_queue));
	q->head = (t_adj*)malloc(sizeof(t_adj));
	q->head->cap = 1;
	q->head->edge = start;
	q->head->prev = NULL;
	q->head->next = NULL;
	q->front = q->head;
	q->rear = q->head;
	return (q);
}

/*
** ***************************************************************************
** int		ft_bfs(t_box *box, t_avl *start, t_avl *end)
** {
** 	t_queue	*q;
** 	t_adj	*u;
** 	t_avl	*prev;
** 	int		level;
** 	int		cnt = -1;
** 	level = 1;
** 	q = ft_init_queue(start);
** 	prev = NULL;
** 	u = start->adj;
** 	while (u)
** 	{
** 		if (u->cap != 0 && ft_is_not_visited(q->head, u->edge) && \
** 				(can_i_pass(prev, q->rear->edge, u) == 1))
** 		{
** 			q->front->next = (t_adj*)malloc(sizeof(t_adj));
** 			q->front->next->edge = u->edge;
** 			q->front->next->next = NULL;
** 			if (q->front->next->edge->level == 0)
** 				q->front->next->edge->level = q->rear->edge->level + 1;
** 			q->front = q->front->next;
** 			if (q->front->edge->id == end->id)
** 				cnt = 1;
** 		}
** 		u = u->next;
** 		if (!u)
** 		{
** 			prev = q->rear->edge;
** 			q->rear = q->rear->next;
** 			if ((q->rear) && q->rear->edge->id == end->id)
** 				q->rear = q->rear->next;
** 			if (!q->rear)
** 				return (cnt);
** 			u = q->rear->edge->adj;
** 		}
** 	}
** 	return (0);
** }
** ***************************************************************************
*/
