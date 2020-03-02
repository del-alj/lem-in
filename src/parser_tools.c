/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:19:34 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/02 17:31:03 by mzaboub          ###   ########.fr       */
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
		ft_printf("{red}%s[%d] {eoc} {bold cyan}%.3d {eoc}:\t", \
				tree->name, tree->taken, tree->level);
		while (adj_temp != NULL)
		{
			ft_printf("{green}%s {eoc} {bold cyan}%.3d {eoc} {yellow}%.3d {eoc}", \
					adj_temp->edge->name, adj_temp->edge->level, adj_temp->cap);
			adj_temp = adj_temp->next;
			if (adj_temp)
				ft_printf(" -->\t");
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
		path = paths[i];
		ft_printf("[%d]\t:", path->len);

		ft_printf("{red}%s {eoc} ", path->vert_name);
		path = path->next;
		while (path->next)
		{
			ft_printf("-- {green}%s {eoc}", path->vert_name);
			path = path->next;
		}
		ft_printf("{red}-- %s {eoc} \n", path->vert_name);
		i++;
	}
}
