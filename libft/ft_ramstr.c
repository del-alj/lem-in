/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ramstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:20:32 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:01:40 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ramstr(char **str, char c)
{
	char	*string;
	size_t	i;
	char	*temp;

	i = 0;
	if (!str[i])
		return (NULL);
	string = ft_strdup(str[i]);
	while (str[++i])
	{
		temp = string;
		string = ft_strjoin(temp, &c);
		free(temp);
		temp = string;
		string = ft_strjoin(temp, str[i]);
		free(temp);
	}
	temp = NULL;
	return (string);
}
