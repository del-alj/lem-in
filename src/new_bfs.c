/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:00:45 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/03 00:20:01 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"



int		bfs(t_box *box, t_avl *start, t_avl *end)
{
	t_queue *q = ft_init_queue(start);
	int		visited[box->vertics_num + 1];
	t_avl	*currentVertex;
	t_adj	*cur_e;
	int		end_reached;
	int		bol_is_some_edge_added;

	ft_memset((void*)visited, 0, (box->vertics_num + 1)* sizeof(int));
	visited[start->id] = 1;
	end_reached = -1;

	while(!is_empty(q))
	{
		currentVertex = dequeue(q);
		cur_e = currentVertex->adj;
		bol_is_some_edge_added = 0;
		while (cur_e != NULL)
		{
			if(cur_e->cap > 0 && (visited[cur_e->edge->id] == 0) && \
				(can_i_pass(q->front->prev, currentVertex, cur_e) == 1))
			{
		//		if (q->front->prev && currentVertex && cur_e)
		//			ft_printf("prev = [%s, %d], cur = [%s, %d], next = [%s, %d].\n", \
						q->front->prev->name, visited[q->front->prev->id], \
						currentVertex->name, visited[currentVertex->id], \
						cur_e->edge->name, visited[cur_e->edge->id]);
				visited[cur_e->edge->id] = 1;
				if (cur_e->edge->level == 0)
					cur_e->edge->level = currentVertex->level + 1;
				enqueue(q, cur_e->edge, cur_e->cap);
				if (cur_e->edge->id == end->id)
					end_reached = 1;
				bol_is_some_edge_added = 1;
			}
			cur_e = cur_e->next;
		}
		if (bol_is_some_edge_added == 0 && currentVertex->id != end->id)
		{
			visited[currentVertex->id] = 0;
			currentVertex->level = 0;
		}

		pop_queue(q);
	}
	return (end_reached);
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
