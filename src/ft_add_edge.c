/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:25:45 by del-alj           #+#    #+#             */
/*   Updated: 2020/03/08 23:18:23 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** ***************************************************************************
*/

static	t_avl	*ft_find(t_avl *tree, char *room)
{
	int	key;

	while (tree && tree->name)
	{
		key = ft_strcmp(tree->name, room);
		if (key < 0)
			tree = tree->right;
		else if (key > 0)
			tree = tree->left;
		else if (key == 0)
			return (tree);
	}
	return (NULL);
}

/*
** ***************************************************************************
*/

static void		ft_push_back(t_avl *link1, t_avl *link2)
{
	t_adj	*l1;

	l1 = link1->adj;
	if (l1 == NULL)
	{
		if (!(link1->adj = (t_adj*)malloc(sizeof(t_adj))))
			exit(EXIT_FAILURE);
		link1->adj->cap = 1;
		link1->adj->next = NULL;
		link1->adj->edge = link2;
	}
	else
	{
		if (ft_strequ(l1->edge->name, link2->name) == 1)
			return ;
		while (l1->next && (ft_strequ(l1->next->edge->name, link2->name) != 1))
			l1 = l1->next;
		if (l1->next != NULL)
			return ;
		if (!(l1->next = (t_adj*)malloc(sizeof(t_adj))))
			return ;
		l1->next->cap = 1;
		l1->next->next = NULL;
		l1->next->edge = link2;
	}
}

/*
** ***************************************************************************
*/

void			ft_add_edge(t_avl **tree, char *r1, char *r2)
{
	t_avl	*link1;
	t_avl	*link2;

	if (!(link1 = ft_find((*tree), r1)))
		ft_error_function((*tree), NULL);
	else if (!(link2 = ft_find((*tree), r2)))
		ft_error_function((*tree), NULL);
	if (ft_strcmp(link1->name, link2->name) == 0)
		ft_error_function((*tree), NULL);
	ft_push_back(link1, link2);
	ft_push_back(link2, link1);
}
