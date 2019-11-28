/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:10:48 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/19 13:11:11 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *next;

	while (*alst != NULL)
	{
		next = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free((void *)*alst);
		*alst = NULL;
		*alst = next;
	}
}
