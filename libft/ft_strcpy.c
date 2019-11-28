/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 04:00:21 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/02 09:10:40 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;
	char	*cst_src;

	i = -1;
	cst_src = (char*)src;
	while (cst_src[++i])
		dest[i] = cst_src[i];
	dest[i] = '\0';
	return (dest);
}
