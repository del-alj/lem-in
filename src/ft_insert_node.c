/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:34:21 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/19 16:16:52 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** **************************************************************************
*/

t_avl	*ft_new_node(t_data data)
{
	t_avl	*node;

	if (!(node = (t_avl*)malloc(sizeof(t_avl))))
		return (NULL);
	node->pos = data.var;
	node->rooms_name = ft_strdup(data.room);
	node->coord_x = data.x;
	node->coord_y = data.y;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	node->adj = NULL;
	return (node);
}

/*
** **************************************************************************
*/

void	ft_insert_node(t_avl **tree, t_data data, t_box *box)
{
	int		balance;
	int		key;
	static int i;

	key = ft_strcmp(data.room, (*tree)->rooms_name);
	if (key == 0)
		ft_error_function((*tree));
	else if ((*tree)->left && key < 0)
		ft_insert_node(&(*tree)->left, data, box);
	else if ((*tree)->right && key > 0)
		ft_insert_node(&(*tree)->right, data, box);
	if ((*tree)->left == NULL && key < 0)
	{
		if(!((*tree)->left = ft_new_node(data)))
			ft_error_function((*tree));
		ft_if_start_end((*tree)->left, data, box);
	}
	else if ((*tree)->right == NULL && key > 0)
	{
		if (!((*tree)->right = ft_new_node(data)))
			ft_error_function((*tree));
		ft_if_start_end((*tree)->right, data, box);
	}
	ft_balance(tree, data);
	return ;
}

/*
** **************************************************************************
*/
