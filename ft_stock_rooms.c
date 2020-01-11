/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:59:52 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/11 13:18:54 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_push(int nb_of_line, char *str, t_data **node, int pos, int i)
{
	(*node)->tab_rooms[(*node)->hash_index] = (t_room*)malloc(sizeof(t_room));
	(*node)->tab_rooms[(*node)->hash_index]->rooms_name = ft_strndup(str, i);
	i++;
	if (!ft_check_nbr(str, i))
		ft_error_function();
	(*node)->tab_rooms[(*node)->hash_index]->coord_x = ft_atoi(str + i);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	i++;
	if (!ft_check_nbr(str, i))
		ft_error_function();
	(*node)->tab_rooms[(*node)->hash_index]->coord_y = ft_atoi(str + i);
	if (pos != 0)
	{
		(*node)->tab_rooms[(*node)->hash_index]->pos = pos;
		pos = 0;
	}
	(*node)->tab_rooms[(*node)->hash_index]->next = NULL;
}

void	ft_back_push(int nb_of_line, char *str, t_data **node, int pos, int i)
{
	t_room *tmp;
	t_room *curent;

	curent = (t_room*)malloc(sizeof(t_room));
	curent->rooms_name = ft_strndup(str, i);
	curent->next = NULL;
	tmp = (*node)->tab_rooms[(*node)->hash_index];
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (!(ft_strcmp(curent->rooms_name, tmp->rooms_name)))
			exit(0);
	}
	i++;
	if (!ft_check_nbr(str, i))
		ft_error_function();
	curent->coord_x = ft_atoi(str + i);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	i++;
	if (!ft_check_nbr(str, i))
		ft_error_function();
	curent->coord_y = ft_atoi(str + i);
	if (pos != 0)
	{
		curent->pos = pos;
		pos = 0;
	}
	curent->next = NULL;
	tmp->next = curent;
}

void	ft_remp_room(int nb_of_line, char *str, t_data **node, int pos)
{
	int	i;

	i = 0;
	(*node)->hash_index = ft_hash_function(str, nb_of_line);
	while (str[i] != ' ')
		i++;
	if ((*node)->tab_rooms[(*node)->hash_index] == NULL)
		ft_push(nb_of_line, str, node, pos, i);
	else
		ft_back_push(nb_of_line, str, node, pos, i);
}

t_data	*ft_stock_rooms(t_stock_file *file, int nb_of_line)
{
	t_stock_file	*head;
	t_data			*node;
	int				pos;

	pos = 0;
	head = file;
	node = ft_alloc_big_tab(nb_of_line);
	node->size_array = nb_of_line;
	while (head->next != NULL && head->next->next != NULL)
	{
		if (ft_strcmp(head->line, "##start") == 0)
			pos = 1;
		else if (ft_strcmp(head->line, "##end") == 0)
			pos = 2;
		if (head->line[0] != '#' && head->line[0] != 'L')
		{
			if (!(ft_strchr(head->line, ' ')))
				ft_error_function();
			ft_remp_room(nb_of_line, head->line, &node, pos);
			pos = 0;
		}
		if (head->line[0] == 'L')
			ft_error_function();
		head = head->next;
	}
	return (node);
}
