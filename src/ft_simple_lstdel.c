/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_lstdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 23:45:56 by mzaboub           #+#    #+#             */
/*   Updated: 2020/03/08 23:57:31 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_simple_lstdel(t_list_simple **alst)
{
	t_list_simple	*head;
	t_list_simple	*nxt;

	head = *alst;
	while (head != NULL)
	{
		nxt = head->next;
		if (head->content)
			free(head->content);
		if (head)
			free(head);
		head = nxt;
	}
	(*alst) = NULL;
}
