/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 04:23:53 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:08:07 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cst_s1;
	unsigned char	*cst_s2;

	cst_s1 = (unsigned char*)s1;
	cst_s2 = (unsigned char*)s2;
	i = -1;
	if (n == 0)
		return (0);
	while (n-- && cst_s1[++i])
		if (cst_s1[i] != cst_s2[i])
			return (cst_s1[i] - cst_s2[i]);
	return (cst_s1[i] - cst_s2[i]);
}
