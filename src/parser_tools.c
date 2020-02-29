/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:19:34 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/28 18:10:15 by del-alj          ###   ########.fr       */
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
		adj_temp = tree->adj;
		ft_printf("{red}%s {eoc} {bold cyan}%d {eoc}:\t", \
				tree->rooms_name, tree->id);
		while (adj_temp != NULL)
		{
			ft_printf("{green}%s {eoc} {yellow}%d {eoc} {yellow}%d {eoc}", adj_temp->n_link->rooms_name, adj_temp->n_link->level, adj_temp->cap);
			adj_temp = adj_temp->next;
			if (adj_temp)
				ft_printf("--> ");
		}
		ft_printf("\n");
		ft_print_link(tree->right, 'r');
		ft_print_link(tree->left, 'l');
	}
}

/*	print the paths	*/


void	ft_print_all_paths(t_path **paths, int maxflow)
{
	int		i;
	t_path	*path;

	i = 0;
	ft_printf("number of paths/max flow value : {cyan}%d {eoc} \n", maxflow);
	while (i < maxflow && paths[i])
	{
		ft_printf("[%d]\t:", paths[i]->len);
		path = paths[i];

		ft_printf("{red}%s {eoc} ", path->vert_name);
		path = path->next;
		while (path->next)
		{
			ft_printf("-- {green}%s {eoc}", path->vert_name);
			path = path->next;
		}
		ft_printf("{red}%s {eoc} \n", path->vert_name);
		i++;
	}
}
