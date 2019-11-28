/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:29:14 by del-alj           #+#    #+#             */
/*   Updated: 2019/10/22 14:43:38 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nm(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nb;
	size_t	len;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	nb = 0;
	len = (size_t)ft_len_nm(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = n * -1;
	}
	nb = n;
	while (i < len)
	{
		str[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
