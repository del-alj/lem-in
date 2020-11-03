/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:35 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/12 20:53:01 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
**	***************************************************************************
*/

static	void	ft_increase_capacity(t_adj *edge, t_avl *v, int flow)
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

static	int		get_edge_cap(t_avl *u, t_avl *v)
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

int				can_i_pass(t_avl *prev, t_avl *u, t_adj *edge)
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
** valid flow is always == 1
*/

int				dfs(t_avl *prev, t_avl *u, t_avl *v, int *level)
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
**	tmp[0] = ret; (0 or 1) either we've found a path or not
**  tmp[1] = tmp; number of paths in last bfs graph we had
** 	valid_paths_nbr how many dfs paths we have in this iteration
**		in the case of score == 0 we initialize the valid_paths_nbr with the
**		old value, since nothin had changed.
*/

int				ft_get_the_max_flow(t_box *head, t_path **paths)
{
	int			tmp[2];
	t_bfs_data	dt;
	int			valid_paths_nbr;
	int			score;

	valid_paths_nbr = 0;
	score = 2147483647;
	if (((dt.level = ft_memalloc((head->vertics_num) * sizeof(int))) == NULL) ||
	((dt.visited = ft_memalloc((head->vertics_num + 1) * sizeof(int))) == NULL))
		exit(EXIT_FAILURE);
	while (bfs(head, head->start, &dt) != -1)
	{
		tmp[1] = valid_paths_nbr;
		while ((tmp[0] = dfs(NULL, head->start, head->end, dt.level)) > 0)
			valid_paths_nbr += tmp[0];
		if (0 == ft_score(head, valid_paths_nbr, &score, paths))
		{
			valid_paths_nbr = tmp[1];
			break ;
		}
		ft_memset(dt.level, 0, head->vertics_num * sizeof(int));
		ft_memset(dt.visited, 0, (head->vertics_num + 1) * sizeof(int));
	}
	ft_free_data(dt);
	return (valid_paths_nbr);
}
