/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:19:01 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/19 13:36:18 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = -1;
	while (++i < n)
	{
		if (src1[i] == (unsigned char)c)
		{
			dst1[i] = src1[i];
			return (&dst[i + 1]);
		}
		dst1[i] = src1[i];
	}
	return (NULL);
}
