/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:19:34 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/27 14:07:45 by mzaboub          ###   ########.fr       */
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
	t_adj *adj_temp;

	if (tree)
	{
		ft_printf("{red}%s {eoc}:\t", tree->rooms_name);
		adj_temp = tree->adj;
		while (adj_temp != NULL)
		{
			ft_printf("{green}%s {eoc}", adj_temp->n_link->rooms_name);
			adj_temp = adj_temp->next;
			if (adj_temp)
				ft_printf("--> ");
		}
		ft_printf("\n");
		ft_print_link(tree->right, 'r');
		ft_print_link(tree->left, 'l');
	}
}
