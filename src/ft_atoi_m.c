/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:31:14 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/19 11:21:05 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

long long		ft_atoi_m(char *str)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	if (str[i] == '-')
	{
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb);
}
/*
int main()
{
	printf("[%lld]\n", ft_atoi_m(""));
	return (0);
}*/
