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

t_data	*ft_stock_file(void)
{
	t_data			*node;
	t_data			*node1;
	int				nb_of_line;
	t_stock_file	*file;
	t_stock_file	*head;

	nb_of_line = 0;
	if (!(node1 = (t_data*)malloc(sizeof(t_data))))
		return (0);
	if (!ft_read_n_ants(node1))
		return (0);
	/*file : contains element need to display - (nbr_ants and links) */
	if (!(file = (t_stock_file*)malloc(sizeof(t_stock_file))))
		return (0);
	head = file;
	nb_of_line = ft_stock_lines(file);
	nb_of_line = ft_prime(nb_of_line);
	node = ft_stock_rooms(file, nb_of_line);
	return (node);
}

