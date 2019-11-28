/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:40:26 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:07:13 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*cst_s;
	unsigned int	i;

	cst_s = (char*)s;
	if (s)
	{
		if (!(str = ft_strnew(ft_strlen(cst_s))))
			return (NULL);
		i = -1;
		while (cst_s[++i])
		{
			str[i] = (*f)(i, cst_s[i]);
		}
		return (str);
	}
	return (NULL);
}
