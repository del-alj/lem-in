/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:33:42 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/19 13:24:39 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lxt;
	t_list	*new_ls;
	t_list	*head_new;

	new_ls = NULL;
	head_new = NULL;
	if (!lst)
		return (NULL);
	lxt = lst;
	new_ls = f(lxt);
	head_new = new_ls;
	while (lxt->next)
	{
		if ((new_ls->next = f(lxt->next)) == NULL)
		{
			ft_lstdel(&head_new, &ft_lst_del_node);
			return (NULL);
		}
		new_ls = new_ls->next;
		lxt = lxt->next;
	}
	return (head_new);
}
