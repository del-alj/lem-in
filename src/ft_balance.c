/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:39:46 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/18 20:30:52 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** **************************************************************************
*/

static	t_avl	*ft_left_retation(t_avl *tree)
{
	t_avl *root;

	root = tree->left;
	tree->left = root->right;
	root->right = tree;
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->height = ft_max(ft_height(root->left), ft_height(root->right)) + 1;
	return (root);
}

/*
** **************************************************************************
*/

static	t_avl	*ft_right_retation(t_avl *tree)
{
	t_avl	*root;

	root = tree->right;
	tree->right = root->left;
	root->left = tree;
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->height = ft_max(ft_height(root->left), ft_height(root->right)) + 1;
	return (root);
}

/*
** **************************************************************************
*/

static	t_avl	*ft_lr_retation(t_avl *tree)
{
	t_avl	*root;
	t_avl	*tmpl;
	t_avl	*tmpr;

	tmpl = tree->left->right->left;
	tmpr = tree->left->right->right;
	root = tree->left->right;
	root->left = tree->left;
	root->right = tree;
	root->right->left = tmpr;
	root->left->right = tmpl;
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->left->height = ft_max(ft_height(root->left->left),
			ft_height(root->left->right)) + 1;
	return (root);
}

/*
** **************************************************************************
*/

static	t_avl	*ft_rl_retation(t_avl *tree)
{
	t_avl	*root;
	t_avl	*tmpl;
	t_avl	*tmpr;

	tmpl = tree->right->left->right;
	tmpr = tree->right->left->left;
	root = tree->right->left;
	root->right = tree->right;
	root->left = tree;
	root->right->left = tmpr;
	root->left->right = tmpl;
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->right->height = ft_max(ft_height(root->right->left),
			ft_height(root->right->right)) + 1;
	return (root);
}

/*
** **************************************************************************
*/

void			ft_balance(t_avl **tree, t_data data)
{
	int		balance;

	balance = 0;
	if ((*tree))
		balance = ft_height((*tree)->left) - ft_height((*tree)->right);
	if (balance < -1)
		(*tree) = (ft_strcmp(data.room, (*tree)->right->rooms_name) > 0) ?
			ft_right_retation((*tree)) : ft_rl_retation((*tree));
	else if (balance > 1)
		(*tree) = (ft_strcmp(data.room, (*tree)->left->rooms_name) < 0) ?
			ft_left_retation((*tree)) : ft_lr_retation((*tree));
	if (balance > 1 || balance < -1)
		(*tree)->height = 1 + ft_max(ft_height((*tree)->left),
				ft_height((*tree)->right));
}
