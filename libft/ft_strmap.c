/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:46:54 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:06:51 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*cst_s;
	int		i;

	cst_s = (char*)s;
	if (s)
	{
		if (!(str = ft_strnew(ft_strlen(cst_s))))
			return (NULL);
		i = -1;
		while (cst_s[++i])
		{
			str[i] = (*f)(cst_s[i]);
		}
		return (str);
	}
	return (NULL);
}
