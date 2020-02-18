/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_fucntion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:11:37 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/18 15:14:01 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** ***************************************************************************
*/

void	ft_free_tree(t_avl *tree)
{
	t_adj	*tmp;

	if (tree == NULL)
		return ;
	ft_free_tree(tree->right);
	ft_free_tree(tree->left);
	free(tree->rooms_name);
	tree->rooms_name = NULL;
	while (tree->adj != NULL)
	{
		tmp = tree->adj;
		tree->adj = tree->adj->next;
		free(tmp);
	}
	tree->adj = NULL;
	free(tree);
	tree = NULL;
}

/*
** ***************************************************************************
*/

void	ft_error_function(t_avl *tree)
{
	ft_free_tree(tree);
	ft_putendl("ERROR");
	exit(0);
}
