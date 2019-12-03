/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:09:03 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/02 16:19:12 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void ft_print_node(t_stc *node, int nb_of_line)
{
	int i;
   
	i = 0;
	printf("ants_nb : %d\n", node->ants_nb);
	while (nb_of_line > i)
	{
		printf("***********tab[%d]**********\ncoord_x : %d\ncoord_y : %d\nname room : %s\nposition : %d\n", i, node->tab_rooms[i].coord_x, node->tab_rooms[i].coord_y, node->tab_rooms[i].rooms_name, node->tab_rooms[i].pos);
		i++;
	}
}

int	ft_stock_file(void)
{
	t_stc			*node;
	int				nb_of_line;
	t_stock_file	*file;
	t_stock_file	*head;

	nb_of_line = 0;
	if (!(node = (t_stc*)malloc(sizeof(t_stc))))
		return (0);
	if (!ft_read_n_ants(node))
		return (0);
	/*file : contains element need to display - (nbr_ants and links) */
	if (!(file = (t_stock_file*)malloc(sizeof(t_stock_file))))
		return (0);
	head = file;
	nb_of_line = ft_stock_lines(file);
	nb_of_line = ft_prime(nb_of_line);
	ft_stock_rooms(file, nb_of_line, node);
	/*just for debug*/
	ft_print_node(node, nb_of_line);
	return (1);
}

int	main()
{
	ft_stock_file();
	printf("ok\n");
	return (0);
}
