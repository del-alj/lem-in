/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:21:33 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:15:08 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*cst_s;
	size_t	len;
	size_t	lent;
	size_t	i;

	if (!s)
		return (NULL);
	cst_s = (char*)s;
	len = ft_strlen(cst_s);
	i = 0;
	while (cst_s[i] == ' ' || cst_s[i] == '\n' || cst_s[i] == '\t')
		i++;
	if (i == len)
		str = ft_strdup("");
	else
	{
		len--;
		while (cst_s[len] == ' '
				|| cst_s[len] == '\n' || cst_s[len] == '\t')
			len--;
		lent = len - i;
		str = ft_strsub(cst_s, i, lent + 1);
	}
	return (str);
}
