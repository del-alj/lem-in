/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_n_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:40:42 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/28 13:02:14 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_read_n_ants(t_stc  *node)
{
	int		i;
	char	*line;

	i = 0;
	if (get_next_line(0, &line) < 0)
		return (0);
	if (!ft_check_nbr(line, i))
	{
		ft_strdel(&line);
		return (0);
	}
	node->ants_nb = ft_atoi(line);
	ft_strdel(&line);
	return (1);
}
