/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 02:03:42 by mzaboub           #+#    #+#             */
/*   Updated: 2020/02/18 11:23:01 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			signe;
	int			i;
	long long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while ((str[i] < 14 && str[i] > 8) || (ft_isspace((int)str[i]) == 1))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		if (nbr > (nbr * 10 + (str[i] - '0')))
			return (signe > 0 ? -1 : 0);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	return (nbr * signe);
}
