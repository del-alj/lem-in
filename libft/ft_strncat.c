/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:17:15 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:07:34 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t cout)
{
	size_t	i;
	size_t	j;
	char	*cst_src;

	i = -1;
	j = -1;
	cst_src = (char*)src;
	while (dest[++i])
		;
	while (cst_src[++j] && j < cout)
		dest[i++] = cst_src[j];
	dest[i] = '\0';
	return (dest);
}
