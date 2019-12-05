/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:39:05 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/30 16:18:57 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft/libft.h"
# include "libft/get_next_line.h"



typedef struct          s_room
{
	int				coord_x;
	int				coord_y;
	char			*rooms_name;
	int				pos;
	int				indx_list;	
	int				link_nb;
    struct s_room	*next;
}                       t_room;
typedef struct      s_data
{
    int     		ants_nb;
    struct s_room  	**tab_rooms;
}                   t_data;

// typedef struct		s_stc
// {
// 	int				ants_nb;
// 	struct s_node	**tab_rooms;
// }					t_stc;



// typedef struct		s_node
// {
// 	int				coord_x;
// 	int				coord_y;
// 	char			*rooms_name;
// 	int				pos;
// 	int				indx_list;	
// 	int				link_nb;
// }					t_node;


// typedef struct  	s_list_rooms
// {
// 	struct s_node	*list;
// 	struct s_list	*next;
// }					t_list_rooms;

typedef struct		s_stock_file
{
	char				*line;
	struct s_stock_file	*next;
}					t_stock_file;

int		ft_check_nbr(char *line, int i);
int		ft_read_n_ants(t_data  *node);
int		ft_hash_function(char *str, int size_array);
int		ft_stock_file();
void    ft_error_function();
int		ft_stock_lines(t_stock_file *file);
t_data  *ft_stock_rooms(t_stock_file *file, int nb_of_line);
int     ft_prime(int nb);
t_data	*ft_alloc_big_tab(int size);

#endif
