/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:02:15 by del-alj           #+#    #+#             */
/*   Updated: 2019/10/18 10:50:04 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		len;
	char		*str;
	char		*cst_src;

	if (src == NULL)
		return (0);
	cst_src = (char*)src;
	len = ft_strlen(cst_src) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (0);
	len = -1;
	while (cst_src[++len])
		str[len] = cst_src[len];
	str[len] = '\0';
	return (str);
}
