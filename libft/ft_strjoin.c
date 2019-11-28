/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:29:50 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:05:37 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_some_len(char const *s1, char const *s2)
{
	size_t	len;
	char	*cst_s1;
	char	*cst_s2;

	cst_s1 = (char*)s1;
	cst_s2 = (char*)s2;
	len = ft_strlen(cst_s1) + ft_strlen(cst_s2);
	return (len);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_some_len(s1, s2);
		str = (char*)ft_memalloc(len + 1);
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
