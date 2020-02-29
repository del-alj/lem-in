/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:02:25 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/29 14:25:44 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_is_not_visited(t_adj *list, t_avl *room)
{
	t_adj	*current;

	current = list;
	while (current)
	{
		if (current->n_link->id == room->id)
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
	q->list = (t_adj*)malloc(sizeof(t_adj));
	q->list->n_link = start;
	q->list->next = NULL;
	q->front = q->list;
	q->rear = q->list;
	return (q);
}

/*
** ***************************************************************************
*/

int		ft_bfs(t_avl *start, t_avl *end)
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
		if (ft_is_not_visited(q->list, u->n_link))
		{
			q->front->next = (t_adj*)malloc(sizeof(t_adj));
			q->front->next->n_link = u->n_link;
			if (q->front->next->n_link->level == 0 && u->cap == 1)
				q->front->next->n_link->level = q->rear->n_link->level + 1;
			q->front->next->next = NULL;
			q->front = q->front->next;
			if (q->front->n_link->id == end->id)
				cnt = 1;
		}
		u = u->next;
		if (!u)
		{
			q->rear = q->rear->next;
			if (!q->rear || (q->rear->n_link->id == end->id))
				return (cnt);
			u = q->rear->n_link->adj;
		}
	}
	return (0);
}
