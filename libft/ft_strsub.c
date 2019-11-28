/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:18:06 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:14:32 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s)
	{
		str = (char*)ft_memalloc(len + 1);
		if (str == NULL)
			return (NULL);
		ft_strncpy(str, (s + start), len);
		return (str);
	}
	return (NULL);
}
