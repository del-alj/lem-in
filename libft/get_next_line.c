/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-makk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:06:15 by ael-makk          #+#    #+#             */
/*   Updated: 2019/05/15 13:23:07 by ael-makk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			line_copy(char *tab, char **line, char *tmp)
{
	int				len;

	len = ft_strlen(tab);
	if (tmp)
		*tmp = '\0';
	*line = ft_strdup(tab);
	if (!*line)
		return (-1);
	if (tmp)
		return (tmp - tab);
	return (len - 1);
}

static int			line_cut(char **tab, char **line, char *tmp, int ret)
{
	char *to_free;

	if (ret < 0)
		return (-1);
	if (**tab == '\0' && !ret)
		return (0);
	if ((ret = line_copy(*tab, line, tmp)) < 0)
		return (-1);
	to_free = *tab;
	if ((*tab)[ret] != '\0')
		ft_strdel(tab);
	else if ((*tab)[ret] == '\0')
	{
		*tab = ft_strdup(*tab + ret + 1);
		ft_strdel(&to_free);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*tab[4864];
	char			*tmp;

	ret = 0;
	if (fd < 0 || !line || fd > 4864)
		return (-1);
	if (!tab[fd])
		tab[fd] = ft_strnew(0);
	while (!(tmp = ft_strchr(tab[fd], '\n')) &&
			(ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = tab[fd];
		if (!(tab[fd] = ft_strjoin(tab[fd], buff)))
			return (-1);
		free(tmp);
	}
	return (line_cut(&tab[fd], line, tmp, ret));
}
