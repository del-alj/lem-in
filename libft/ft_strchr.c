/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:19:55 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:02:15 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*cst_s;
	int		i;

	i = -1;
	cst_s = (char*)s;
	while (cst_s[++i])
		if (cst_s[i] == c)
			return (cst_s + i);
	if (cst_s[i] == c)
		return (cst_s + i);
	return (NULL);
}
