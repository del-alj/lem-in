/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 04:10:41 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:09:07 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const	char *src, size_t n)
{
	size_t	i;
	char	*cst_src;

	i = -1;
	cst_src = (char*)src;
	while (cst_src[++i] && i < n)
		dest[i] = cst_src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
