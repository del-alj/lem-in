/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_fucntion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:11:37 by del-alj           #+#    #+#             */
/*   Updated: 2020/11/03 09:14:44 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
**	***************************************************************************
*/

void	ft_free_data(t_bfs_data dt)
{
	ft_memdel((void**)&dt.visited);
	ft_memdel((void**)&dt.level);
	if (dt.q != NULL)
		ft_free_queue(&dt.q);
}

/*
**	***************************************************************************
*/

void	ft_free_queue(t_queue **q)
{
	t_adj	*head;
	t_adj	*nxt;

	if (q && *q)
	{
		head = (*q)->head;
		while (head != NULL)
		{
			nxt = head->next;
			ft_memdel((void**)&head);
			head = nxt;
		}
		ft_memdel((void**)q);
		*q = NULL;
	}
}

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
	free(tree->name);
	tree->name = NULL;
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

void	ft_error_function(t_avl *tree, char *str)
{
	ft_free_tree(tree);
	if (str)
	{
		ft_putstr("ERROR: ");
		ft_putstr(str);
		ft_putchar('\n');
	}
	else
		ft_putstr("ERROR.\n");
	exit(0);
}
