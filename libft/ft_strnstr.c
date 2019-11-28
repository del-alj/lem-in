/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:26:47 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:11:10 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const	char *s, const char *to, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cst_str;
	char	*cst_to_find;

	j = 0;
	i = 0;
	cst_str = (char*)s;
	cst_to_find = (char*)to;
	if (cst_to_find[j] == '\0')
		return (cst_str);
	while (cst_str[i] && i < len)
	{
		j = 0;
		while (cst_to_find[j] == cst_str[i + j] && (i + j) < len)
		{
			if (cst_to_find[j + 1] == '\0')
				return (cst_str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
