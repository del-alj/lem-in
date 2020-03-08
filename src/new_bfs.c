/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:00:45 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/08 19:36:53 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		bfs(t_box *box, t_avl *start, t_bfs_data *data)
{
	//t_queue *q;
	t_adj	*cur_e;
	int		end_reached;
	t_avl	*curr_vertex;
	int		bol_is_some_edge_added;

	end_reached = -1;
	data->q = ft_init_queue(start);
	data->visited[start->id] = 1;
	while (!is_empty(data->q))
	{
		curr_vertex = dequeue(data->q);
		cur_e = curr_vertex->adj;
		bol_is_some_edge_added = 0;
		end_reached += ft_bfs_extentions(box, cur_e, data->visited, data->q, data->level, curr_vertex);
		pop_queue(data->q);
	}
	return ((end_reached == 0) ? 0 : 1);
}

int		ft_bfs_extentions(t_box *box, t_adj *cur_e, int *visited, t_queue *q, int *level, \
						  t_avl *curr_vertex)
{
	int		is_end_reached;
	int		bol_is_some_edge_added;

	is_end_reached = 0;
	bol_is_some_edge_added = 0;
	while (cur_e != NULL)
	{
		if (cur_e->cap > 0 && (visited[cur_e->edge->id] == 0) && \
			(can_i_pass(q->front->prev, curr_vertex, cur_e) == 1))
		{
			visited[cur_e->edge->id] = 1;
			if (level[cur_e->edge->id] == 0)
				level[cur_e->edge->id] = level[curr_vertex->id] + 1;
			enqueue(q, cur_e->edge, cur_e->cap);
			if (cur_e->edge->id == box->end->id)
				is_end_reached = 1;
			bol_is_some_edge_added = 1;
		}
		cur_e = cur_e->next;
	}
	if (bol_is_some_edge_added == 0 && curr_vertex->id != box->end->id)
	{
		visited[curr_vertex->id] = 0;
		level[curr_vertex->id] = 0;
	}
	return (is_end_reached);
}

int		is_empty(t_queue *q)
{
	if (q->front == NULL)
		return (1);
	return (0);
}

void	enqueue(t_queue *q, t_avl *node, int cap)
{
	q->rear->next = (t_adj*)ft_memalloc(sizeof(t_adj));
	q->rear->next->edge = node;
	q->rear->next->cap = cap;
	q->rear->next->prev = q->front->edge;
	q->rear->next->next = NULL;
	q->rear = q->rear->next;
}

t_avl	*dequeue(t_queue *q)
{
	return (q->front->edge);
}

void	pop_queue(t_queue *q)
{
	q->front = q->front->next;
}
