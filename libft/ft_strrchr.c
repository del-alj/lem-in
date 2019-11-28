/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:41:03 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:11:41 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cst_s;

	cst_s = (char*)s;
	i = ft_strlen(cst_s);
	while (i >= 0)
	{
		if (cst_s[i] == c)
			return (cst_s + i);
		i--;
	}
	return (NULL);
}
