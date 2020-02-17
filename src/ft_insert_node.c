/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:34:21 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/17 09:37:38 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

/*
** **************************************************************************
*/

t_avl	*ft_new_node(int key)
{
	t_avl	*node;

	if (!(node = (t_avl*)malloc(sizeof(t_avl))))
		return (NULL);
	node->key = key;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/*
** **************************************************************************
*/

void	ft_insert_node(t_avl **tree, int key)
{
	int		balance;

	if ((*tree)->left && key < (*tree)->key)
		ft_insert_node(&(*tree)->left, key);
	else if ((*tree)->right && key > (*tree)->key)
		ft_insert_node(&(*tree)->right, key);
	if ((*tree)->left == NULL && key < (*tree)->key)
		(*tree)->left = ft_new_node(key);
	else if ((*tree)->right == NULL && key > (*tree)->key)
		(*tree)->right = ft_new_node(key);
	ft_balance(tree, key);
}

/*
** **************************************************************************
*/
