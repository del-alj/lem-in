/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:07:33 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/07 00:19:27 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(unsigned long long int n, int base)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(long long int nb, int base)
{
	unsigned long long		n;
	int						len;
	char					*str;
	char					*hex;

	len = 0;
	hex = ft_strdup("0123456789abcdef");
	if (nb < 0 && base == 10)
	{
		n = (unsigned long long)nb * -1;
		len++;
	}
	else
		n = (unsigned long long)nb;
	len = len + ft_len_num(n, base);
	str = ft_strnew(len);
	while (len > 0)
	{
		str[--len] = hex[n % base];
		n /= base;
		if (len == 0 && nb < 0 && base == 10)
			str[0] = '-';
	}
	ft_strdel(&hex);
	return (str);
}
