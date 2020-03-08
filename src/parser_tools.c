/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:19:34 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/08 23:54:00 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

char	*ft_escap_whitspace(char *str)
{
	while (str && ft_isspace((int)*str))
		str++;
	return (str);
}

/*
** ***************************************************************************
*/

void	ft_print_link(t_avl *tree)
{
	t_adj	*adj_temp;

	if (tree)
	{
		adj_temp = tree->adj;
		ft_printf("{red}%s[%d] {eoc} :\t", \
				tree->name, tree->taken);
		while (adj_temp != NULL)
		{
			ft_printf("{green}%s {eoc}  {yellow}%.3d {eoc}", \
					adj_temp->edge->name, adj_temp->cap);
			adj_temp = adj_temp->next;
			if (adj_temp)
				ft_printf("-->   ");
		}
		ft_printf("\n");
		ft_print_link(tree->right);
		ft_print_link(tree->left);
	}
}

/*
** ***************************************************************************
*/

void	ft_print_all_paths(t_path *paths, int maxflow)
{
	int				i;
	t_list_simple	*path;

	i = 0;
	ft_printf("number of paths/max flow value : {cyan}%d {eoc} \n", maxflow);
	while ((i < maxflow) && (paths + i != NULL))
	{
		path = paths[i].list;
		ft_printf("[%d]\t:", paths[i].len);
		while (path->next)
		{
			ft_printf("-- {green}%s {eoc}", path->content);
			path = path->next;
		}
		ft_printf("{red}-- %s {eoc} \n", path->content);
		i++;
	}
}

/*
** ***************************************************************************
*/
