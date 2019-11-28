/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:51:57 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/28 13:09:53 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/*
int	ft_stock_links(t_stc node, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '-')
		i++;
	//linked with = ft_strndup(line, i);
	i++;
	//linked with  = ft_strdup(line + i);
	if (linked exist != NULL)
		return (0);
	return (1);

}
*/

int	ft_stock_file()
{
	t_stc   		*node;
	t_list_rooms	*list_rooms;
	int				pos;
	char			*line;

	if (!(node = (t_stc*)malloc(sizeof(t_stc))))
		return (0);
	if (!(list_rooms = (t_list_rooms*)malloc(sizeof(t_list_rooms))))
		return (0);
	//if (!(node->tab_rooms = (t_node*)malloc(sizeof(t_stc) * ()))
	//	return (0);
	if (!ft_read_n_ants(node))
		return (0);
	while (get_next_line(0, &line) < 0)
	{
		pos = 0;
		if (!ft_strcmp(line, "##start"))
			pos = 1;	
		if (!ft_strcmp(line, "##end"))
			pos = 2;
		if (!ft_strchr(line, '#'))
		{
			if (!ft_strchr(line, '-') || ft_strchr(line, ' '))
			{
				if (!ft_read_room(list_rooms, line))
					return (0);
				//if (pos == 1)
				//	node->pos = ft_strdup("start");
			}
			/*if (!ft_strchr(line, ' ') && ft_strchr(line, '-'))
			{
				if(!ft_ft_stock_links(node, line))
					return (0);
				//if (pos == 2)
				//	node->pos = ft_strdup("end");
			}*/
		}
		ft_strdel(&line);
	}
	return (1);
}
