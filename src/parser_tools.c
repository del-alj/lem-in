/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:19:34 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/19 14:47:57 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

char *ft_escap_whitspace(char *str)
{
	while (str && ft_isspace((int)*str))
		str++;
	return (str);
}


/* Print nodes at a given level */

void	ft_print_link(t_avl *tree , char c)
{
	if (tree)
	{
		ft_printf("{%s} :\t", tree->rooms_name);
		while (tree->adj != NULL)
		{
			ft_printf("[%s]", tree->adj->n_link->rooms_name);
			tree->adj = tree->adj->next;
		}
		ft_printf("\n");
		ft_print_link(tree->right, 'r');
		ft_print_link(tree->left, 'l');
	}
}
