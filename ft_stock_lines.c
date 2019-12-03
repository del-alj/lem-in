/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:48:43 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/02 16:20:31 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_stock_lines(t_stock_file *file)
{
	int	nb_of_line;

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
