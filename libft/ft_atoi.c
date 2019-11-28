/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 04:26:06 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/19 09:33:01 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int			i;
	long int	sign;
	long int	nb;
	char		*cst_str;

	cst_str = (char*)str;
	i = 0;
	sign = 1;
	nb = 0;
	while (cst_str[i] == ' ' || cst_str[i] == '\t' || cst_str[i] == '\n'
			|| cst_str[i] == '\v' || cst_str[i] == '\f' || cst_str[i] == '\r')
		i++;
	if (cst_str[i] == '+')
		i++;
	if (cst_str[i] == '-' && cst_str[i - 1] != '+')
	{
		sign = -1;
		i++;
	}
	while (cst_str[i] >= '0' && cst_str[i] <= '9')
	{
		nb = (nb * 10) + cst_str[i] - '0';
		i++;
	}
	return ((int)(sign * nb));
}
