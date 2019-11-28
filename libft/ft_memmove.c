/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 01:29:34 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 22:52:27 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cst_src;
	unsigned char	*cst_dst;
	unsigned char	*temp;
	size_t			i;

	cst_dst = (unsigned char*)dst;
	cst_src = (unsigned char*)src;
	i = -1;
	if (cst_dst > cst_src + len)
		while (++i < len)
			cst_dst[i] = cst_src[i];
	else
	{
		temp = (unsigned char*)malloc(len * sizeof(unsigned char));
		if (temp == 0)
			return (NULL);
		while (++i < len)
			temp[i] = cst_src[i];
		i = -1;
		while (++i < len)
			cst_dst[i] = temp[i];
		free(temp);
	}
	return (dst);
}
