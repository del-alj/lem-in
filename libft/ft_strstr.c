/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 04:25:19 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/11 18:04:16 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s, const char *to)
{
	int		i;
	int		j;
	char	*cst_str;
	char	*cst_to_find;

	i = 0;
	j = 0;
	cst_str = (char*)s;
	cst_to_find = (char*)to;
	if (cst_to_find[j] == '\0')
		return (cst_str);
	while (cst_str[i])
	{
		j = 0;
		while (cst_to_find[j] == cst_str[i + j])
		{
			if (cst_to_find[j + 1] == '\0')
				return (cst_str + i);
			j++;
		}
		i++;
	}
	return (0);
}
