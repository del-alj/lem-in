/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:32:14 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/16 17:13:42 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_avl
{
	int				key;
	int				height;
	struct	s_avl	*left;
	struct  s_avl	*right;
}				t_avl;

void	ft_print_tree(t_avl *tree, char c)
{
	if (tree == NULL)
		return ;
	printf("%d - %c -> %d\n", tree->key, c, tree->height);
	ft_print_tree(tree->right, 'r');
	ft_print_tree(tree->left, 'l');
}

t_avl	*ft_new_node(int key)
{
	t_avl	*node;

	if (!(node = (t_avl*)malloc(sizeof(t_avl))))
		return (NULL);
	node->key = key;
	node->height = 1;
	node->left = NULL;
	node->right= NULL;
	return (node);
}

int		ft_height(t_avl *node)
{
	if (node)
		return (node->height);
	else
		return (0);

}

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

t_avl	*ft_left_retation(t_avl *tree)
{
	t_avl *root;

	root = tree->left;
	tree->left = root->right;
	root->right = tree;
	
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->height = ft_max(ft_height(root->left), ft_height(root->right)) + 1;
	return (root);
}

t_avl   *ft_right_retation(t_avl *tree)
{
	t_avl *root;

	root = tree->right;
	tree->right = root->left;
	root->left = tree;
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->height = ft_max(ft_height(root->left), ft_height(root->right)) + 1;
	printf("ok\n");
	return (root);
}

 t_avl   *ft_lr_retation(t_avl *tree)
{
	t_avl *root;
	t_avl *tmpl;
	t_avl *tmpr;

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


 t_avl   *ft_rl_retation(t_avl *tree)
{
	t_avl *root;
	t_avl *tmpl;
	t_avl *tmpr;
	
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

void	ft_balance(t_avl **tree, int key)
{
	int     balance;
	
	balance = 0;
	(*tree)->height = 1 + ft_max(ft_height((*tree)->left),
			ft_height((*tree)->right));
	if ((*tree))
		balance = ft_height((*tree)->left) - ft_height((*tree)->right);
	if (balance < -1)
		(*tree) = (key > (*tree)->right->key) ?
			ft_right_retation((*tree)) : ft_rl_retation((*tree));
	else if (balance > 1)
	(*tree) = (key < (*tree)->left->key) ?
			ft_left_retation((*tree)) :  ft_lr_retation((*tree));
}

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

int	main()
{
//	int	tab[2] = {10, 9};
//	int tab[2] = {-3, 0};
//	int tab[2] = {10, 11};
//	int tab[5] = {2, 9, 8, 12, 10};
	int tab[5] = {6, 4, 8, 25, 14};
	t_avl   *tree;
	int i = 5;
	tree = ft_new_node(3);
	ft_print_tree(tree, 'b');
	while (i)
	{
		ft_insert_node(&tree, tab[i - 1]);
		i--;
	}
	// print tree
	ft_print_tree(tree, 'o');
	return (0);
}
