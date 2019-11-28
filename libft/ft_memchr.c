/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:32:14 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/19 13:43:47 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cst;
	size_t			i;

	i = -1;
	cst = (unsigned char*)s;
	while (++i < n)
		if (cst[i] == (unsigned char)c)
			return ((void *)(cst + i));
	return (NULL);
}
