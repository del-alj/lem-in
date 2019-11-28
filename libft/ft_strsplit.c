/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:20:59 by del-alj           #+#    #+#             */
/*   Updated: 2019/04/14 23:13:19 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char *str, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] == c)
				|| (str[i] != c && str[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w + 1);
}

static size_t	ft_charlen(char *str, char c)
{
	size_t	s;
	size_t	i;

	s = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			s++;
		i++;
	}
	return (s);
}

static size_t	ft_cont(char *cst_s, size_t i, char c)
{
	while (cst_s[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*cst_s;
	char	**array;
	size_t	i;
	size_t	w;
	size_t	j;

	if (!s || (w = 0))
		return (NULL);
	cst_s = (char*)s;
	i = 0;
	if (!(array = (char**)malloc((ft_words(cst_s, c)) * sizeof(char*))))
		return (NULL);
	while (cst_s[i] && ft_words(cst_s, c) > w)
	{
		j = 0;
		if (!(array[w] = ft_strnew((ft_charlen(cst_s, c)))))
			return (0);
		i = ft_cont(cst_s, i, c);
		while (cst_s[i] != c && cst_s[i] != '\0')
			array[w][j++] = cst_s[i++];
		array[w][j] = '\0';
		w++;
	}
	array[j == 0 ? w - 1 : w] = 0;
	return (array);
}
