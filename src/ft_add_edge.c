/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:25:45 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/18 12:02:25 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** ***************************************************************************
*/

t_avl	*ft_find(t_avl *tree, char *room)
{
	int	key;

	while (tree && tree->rooms_name)
	{
		key = ft_strcmp(room, tree->rooms_name);
		if (key > 0)
			tree = tree->right;	
		else if (key == 0)
			return (tree);
		else if (key < 0)
			tree = tree->left;
	}
	return (NULL);
}

/*
** ***************************************************************************
*/

void	ft_push_back(t_avl *link1, t_avl *link2)
{
	t_avl *room;

	room = link1;
	if (room->adj == NULL)
	{
		room->adj = (t_adj*)malloc(sizeof(t_adj));
		room->adj->n_link = link2;
		room->adj->next = NULL;
	}
	else
	{
		while (room->adj->next != NULL)
			room->adj = room->adj->next;
		room->adj->next = (t_adj*)malloc(sizeof(t_adj));
		room->adj->next->n_link = link2;
		room->adj->next->next = NULL;
	}
}

/*
** ***************************************************************************
*/

void	ft_add_edge(t_avl *tree, char *r1, char *r2)
{		
	t_avl	*link1;
	t_avl	*link2;

	if (!(link1 = ft_find(tree,  r1)))
		ft_error_function();
	else if (!(link2 = ft_find(tree,  r2)))
		ft_error_function();
	if (ft_strcmp(link1->rooms_name, link2->rooms_name) == 0)
		ft_error_function();
	ft_push_back(link1, link2);
	ft_push_back(link2, link1);
//	ft_print_link(tree, 'o');
	return ;
}

/*
** ***************************************************************************
*/
