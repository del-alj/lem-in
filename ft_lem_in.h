/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:39:05 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/28 13:10:25 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct		s_stc
{
	int				ants_nb;
	struct s_node	*tab_rooms;
}					t_stc;

typedef struct		s_node
{
	int				coord_x;
	int				coord_y;
	char			*rooms_name;
	char			*pos;
	int				hash_nb;
	int				indx_list;	
	int				link_nb;
}					t_node;

typedef struct  	s_list_rooms
{
	struct s_node	*list;
	struct  s_list	*next;
}					t_list_rooms;

int		ft_check_nbr(char *line, int i);
int		ft_read_n_ants(t_stc  *node);
int		ft_read_room(t_list_rooms *list_rooms, char *line);
int		ft_stock_file();

#endif
