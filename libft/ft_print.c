/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:44:42 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 22:53:11 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(void *ptr, int idx)
{
	int		*n;
	char	*str;

	if (idx == 0)
	{
		n = (int*)ptr;
		ft_putnbr(*n);
	}
	else if (idx == 1)
	{
		str = (char*)ptr;
		ft_putstr(str);
	}
}
