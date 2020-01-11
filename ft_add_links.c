/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:22:16 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/05 20:22:18 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void ft_print_node(t_data *node)
{
	int i;
   
	i = 0;
	//printf("ants_nb : %d\n", node->ants_nb);
	while (node->size_array > i)
	{
		if (node && node->tab_rooms[i])
		{	printf("***********tab[%d]**********\ncoord_x : %d\ncoord_y : %d\nname room : %s\nposition : %d\n", i, node->tab_rooms[i]->coord_x, node->tab_rooms[i]->coord_y, node->tab_rooms[i]->rooms_name, node->tab_rooms[i]->pos);
			if (node->tab_rooms[i]->link_room)
                printf("-----> %s <----------\n", node->tab_rooms[i]->link_room->rooms_name);
			node->tab_rooms[i] = node->tab_rooms[i]->next;
			// if (node->tab_rooms[i] != NULL)
			// {	printf("***********tab[%d]**********\ncoord_x : %d\ncoord_y : %d\nname room : %s\nposition : %d\n", i, node->tab_rooms[i]->coord_x, node->tab_rooms[i]->coord_y, node->tab_rooms[i]->rooms_name, node->tab_rooms[i]->pos);
			// }
		}
		i++;
	}
}

void    ft_add_add_links(t_data *node)
{
    t_data  *head;
    t_room  *link_a;
    t_room  *link_b;
    char    *line;
    int     hash_index;
    char    *str;
    int     i;

    head = node;
    while (get_next_line(0, &line) > 0)
	{
        i = 0;
       printf("ok\n");
        while (line[i] && line[i] != '-')
            i++;
        if (line[i] == '-')
        {
            str = ft_strndup(line, i);
            hash_index = ft_hash_function(str, node->size_array);
            if (head->tab_rooms[hash_index]->rooms_name)
            {
                while (head->tab_rooms[hash_index] && head->tab_rooms[hash_index]->rooms_name && ft_strcmp(str, head->tab_rooms[hash_index]->rooms_name))
                {
                    head->tab_rooms[hash_index] = head->tab_rooms[hash_index]->next;
                }
                if (head->tab_rooms[hash_index]->rooms_name)
                {
                    link_a = (t_room*)malloc(sizeof(t_room));
                    link_a = head->tab_rooms[hash_index];
                }
            }
            else
                ft_error_function();
            i++;
            int j = 0;
            ft_strdel(&str);
            str = ft_strdup(line + i);
            hash_index = ft_hash_function(str, node->size_array);
            if (head->tab_rooms[hash_index]->rooms_name)
            {
                while (head->tab_rooms[hash_index] && head->tab_rooms[hash_index]->rooms_name && ft_strcmp(str, head->tab_rooms[hash_index]->rooms_name))
                {
                    head->tab_rooms[hash_index] = head->tab_rooms[hash_index]->next;
                }
                if (head->tab_rooms[hash_index]->rooms_name)
                {
                    link_b = (t_room*)malloc(sizeof(t_room));
                    link_b = head->tab_rooms[hash_index];
                }
            }
            else
                ft_error_function();
            if (!(link_a->link_room) && !(link_b->link_room))
            {
                link_a->link_room = (t_room*)malloc(sizeof(t_room));
                link_a->link_room = link_b;
                link_a->link_nb++;
                link_b->link_nb++;
                link_b->link_room = (t_room*)malloc(sizeof(t_room));
                link_b->link_room = link_a;
            }
             else
            {
               // link_a->link_room->
               printf("okdoky\n");
            }
            link_a->link_room->link_room = (t_room*)malloc(sizeof(t_room));
            link_b->link_room->link_room = (t_room*)malloc(sizeof(t_room));
            link_b->link_room->link_room = NULL;
            link_a->link_room->link_room = NULL;
            }
        }
    ft_print_node(node);
}

int	main()
{
	t_data *node;
	
	node = ft_stock_file();
    ft_add_add_links(node);
	return (0);
}
