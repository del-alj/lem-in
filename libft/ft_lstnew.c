/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:09:28 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 22:49:28 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lsnew;

	if (!(lsnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		lsnew->content = NULL;
		lsnew->content_size = 0;
	}
	else
	{
		if (!(lsnew->content = malloc(content_size)))
		{
			free(lsnew);
			return (NULL);
		}
		ft_memcpy((lsnew->content), content, content_size);
		lsnew->content_size = content_size;
	}
	lsnew->next = NULL;
	return (lsnew);
}
