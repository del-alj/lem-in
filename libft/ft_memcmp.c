/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:41:58 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 22:51:17 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cst_s1;
	unsigned char	*cst_s2;

	cst_s1 = (unsigned char *)s1;
	cst_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*cst_s1 != *cst_s2)
			return (*cst_s1 - *cst_s2);
		cst_s1++;
		cst_s2++;
	}
	return (0);
}
