/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:44:38 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 22:51:44 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cst_dst;
	char	*cst_src;
	size_t	i;

	cst_dst = (char*)dst;
	cst_src = (char*)src;
	i = -1;
	while (++i < n)
		cst_dst[i] = cst_src[i];
	return (dst);
}
