/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_big_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:21:12 by del-alj           #+#    #+#             */
/*   Updated: 2019/12/04 19:21:16 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

t_data    *ft_alloc_big_tab(int size)
{
    t_data  *s3;
    int   i;

    i = -1;
    s3 = (t_data*)malloc(sizeof(t_data));
    s3->tab_rooms = (t_room**)malloc(sizeof(t_room*) * size);
    
    while (++i < size )
        s3->tab_rooms[i] = NULL;
    return (s3);
}
