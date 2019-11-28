/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:24:34 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:06:02 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	i = -1;
	j = -1;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	while (dst[++i])
		;
	if (len_dst < size)
		while (i < size - 1)
			dst[i++] = ((char *)src)[++j];
	dst[i] = '\0';
	return (len_dst < size ? (len_dst + len_src) : (len_src + size));
}
