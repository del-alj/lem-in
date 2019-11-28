/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:51:00 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 22:47:22 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_next(t_list **list, t_list *node)
{
	t_list	*current;

	if (list && node && *list)
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}
