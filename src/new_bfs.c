/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:00:45 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/12 20:42:38 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** ***************************************************************************
*/

int		bfs(t_box *box, t_avl *start, t_bfs_data *data)
{
	t_adj	*cur_e;
	int		end_reached;
	t_avl	*curr_vertex;
	int		bol_is_some_edge_added;

	end_reached = -1;
	data->q = ft_init_queue(start);
	data->visited[start->id] = 1;
	while (data->q->front != NULL)
	{
		curr_vertex = dequeue(data->q);
		cur_e = curr_vertex->adj;
		bol_is_some_edge_added = 0;
		end_reached += ft_bfs_extentions(box, data, cur_e, curr_vertex);
		data->q->front = data->q->front->next;
	}
	ft_free_queue(&(data->q));
	data->q = NULL;
	return ((end_reached == 0) ? 0 : 1);
}

/*
** ***************************************************************************
** bol[0] == is_end_reached;
** bol[1] == bol_is_some_edge_added;
*/

int		ft_bfs_extentions(t_box *box, t_bfs_data *data, \
							t_adj *cur_e, t_avl *curr_vertex)
{
	int		bol[2];

	ft_memset((void*)bol, 0, sizeof(int) * 2);
	while (cur_e != NULL)
	{
		if (cur_e->cap > 0 && (data->visited[cur_e->edge->id] == 0) && \
			(can_i_pass(data->q->front->prev, curr_vertex, cur_e) == 1))
		{
			data->visited[cur_e->edge->id] = 1;
			if (data->level[cur_e->edge->id] == 0)
				data->level[cur_e->edge->id] = data->level[curr_vertex->id] + 1;
			enqueue(data->q, cur_e->edge, cur_e->cap);
			bol[1] = 1;
			if (cur_e->edge->id == box->end->id)
				bol[0] = 1;
		}
		cur_e = cur_e->next;
	}
	if (bol[1] == 0 && curr_vertex->id != box->end->id)
	{
		data->visited[curr_vertex->id] = 0;
		data->level[curr_vertex->id] = 0;
	}
	return (bol[0]);
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
*/

void	enqueue(t_queue *q, t_avl *node, int cap)
{
	q->rear->next = (t_adj*)ft_memalloc(sizeof(t_adj));
	q->rear->next->edge = node;
	q->rear->next->cap = cap;
	q->rear->next->prev = q->front->edge;
	q->rear->next->next = NULL;
	q->rear = q->rear->next;
}

/*
** ***************************************************************************
*/

t_avl	*dequeue(t_queue *q)
{
	return (q->front->edge);
}

/*
** ***************************************************************************
*/
