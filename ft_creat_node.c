/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:21:26 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/04 19:21:30 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_creat_node(t_data *s3, char *str, int i)
{
    s3->tab_rooms[i] = (t_room*)malloc(sizeof(t_room));
    s3->tab_rooms[i]->rooms_name = ft_strdup(str);
    s3->tab_rooms[i]->next = NULL;
}
