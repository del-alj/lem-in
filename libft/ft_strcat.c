/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 04:15:10 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/02 10:04:49 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*cst_src;

	i = -1;
	j = -1;
	cst_src = (char*)src;
	while (dest[++i])
		;
	while (cst_src[++j])
	{
		dest[i] = cst_src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
