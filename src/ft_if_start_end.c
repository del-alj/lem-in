/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_start_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:14:54 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/22 13:12:56 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
 ** **************************************************************************
*/

void	ft_if_start_end(t_avl *node, t_data data, t_box *box)
{
	if (data.var == 'S')
		box->start = node;
	else if (data.var == 'E')
		box->end = node;
}

/*
** ***************************************************************************
*/