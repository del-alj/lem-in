/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:15:07 by mzaboub           #+#    #+#             */
/*   Updated: 2020/11/03 10:15:08 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** ****************************************************************************
*/

int		ft_len_adj(t_adj *list)
{
	int		len;
	t_adj	*current;

	len = 0;
	current = list;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

/*
** ****************************************************************************
** reads whats the max start can give and the max sink can get
** so that you can know the max-flow the graph can take at each turn.
*/

void	ft_count_bottleneck_edges(t_box *head)
{
	int	p_end;
	int	p_start;

	p_start = ft_len_adj(head->start->adj);
	p_end = ft_len_adj(head->end->adj);
	head->ports = (p_start > p_end) ? p_end : p_start;
}

/*
** ****************************************************************************
** ft_print_all_paths(paths, ret);
*/

int		main(void)
{
	t_box			head;
	int				ret;
	char			*buff;
	t_path			*paths;
	const	char	*error[3] = {"NO ROOMS", "NO EDGES", "NO START/END ROOM"};

	head.tree = NULL;
	head.start = NULL;
	head.end = NULL;
	head.ants_nbr = 0;
	paths = NULL;
	ret = ft_read_input(&head, &buff);
	//ft_printf("%s\n\n\n", buff);
	ft_putstr(buff);
	ft_putstr("\n\n\n");
	head.vertics_num++;
	if (ret < 2)
		ft_error_function(head.tree, (char*)error[ret]);
	ft_count_bottleneck_edges(&head);
	ret = ft_get_the_max_flow(&head, &paths);
	ft_pass_ants(paths, ret, head.ants_nbr);
	ft_free_tree(head.tree);
	ft_memdel((void**)&buff);
	ft_free_path_group(&paths);
	ft_memdel((void**)&paths);
	return (0);
}

/*
** ****************************************************************************
*/
