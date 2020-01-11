/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:09:03 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/11 13:58:01 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
** ***************************************************************************
*/

int		ft_stock_lines(t_stock_file *file)
{
	int		nb_of_line;

	nb_of_line = 0;
	file->line = NULL;
	while (get_next_line(0, &file->line) > 0)
	{
		if (file->line[0] == '\0')
			ft_error_function();
		if (ft_strchr(file->line, '-'))
		{
			file->next = malloc(sizeof(t_stock_file));
			file = file->next;
			file->next = NULL;
			break ;
		}
		if (file->line[0] != '#' && file->line[0] != 'L')
			nb_of_line++;
		file->next = malloc(sizeof(t_stock_file));
		file = file->next;
		file->line = NULL;
	}
	if (nb_of_line == 0 || file->line == NULL)
		ft_error_function();
	return (nb_of_line);
}

/*
** **************************************************************************
*/

int		ft_read_n_ants(t_data *node)
{
	int		i;
	char	*line;

	i = 0;
	if (get_next_line(0, &line) <= 0)
		ft_error_function();
	if (!ft_check_nbr(line, i))
		ft_error_function();
	node->ants_nb = ft_atoi(line);
	ft_strdel(&line);
	return (1);
}

/*
**file : contains element need to display - (nbr_ants and links)
*/

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
	if (!(file = (t_stock_file*)malloc(sizeof(t_stock_file))))
		return (0);
	head = file;
	nb_of_line = ft_stock_lines(file);
	nb_of_line = ft_prime(nb_of_line);
	node = ft_stock_rooms(file, nb_of_line);
	return (node);
}
