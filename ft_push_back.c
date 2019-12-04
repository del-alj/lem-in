/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:21:40 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/04 19:21:41 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_push_back(t_data *s3, char *str, int i)
{
    t_room *tmp;
    t_room *node;

    node = (t_room*)malloc(sizeof(t_room));
    node->rooms_name = ft_strdup(str);
    node->next = NULL;    
    tmp =s3->tab_rooms[i];
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (!(ft_strcmp(node->rooms_name, tmp->rooms_name)))
            exit(0);
    }
    tmp->next = node;
}
