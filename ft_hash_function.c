/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:01:00 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/02 16:42:01 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_hash_function(char *str, int size_array)
{
	int	key;
	int	i;

	i = 0;
	key = 0;
	while (str[i] != '\0' && str[i] != ' ')
	{
		key = str[i] * (i + 1) + key;
		i++;
	}
	return (key % size_array);
}
