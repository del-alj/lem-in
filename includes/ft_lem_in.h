/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:39:05 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/18 08:02:03 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

#include <stdio.h>
# include "../libftprintf/headers/libft.h"
# include "../libftprintf/headers/ft_printf.h"

//# include "libft/get_next_line.h"



typedef struct          s_room
{
	int				coord_x;
	int				coord_y;
	char			*rooms_name;
	int				pos;
	int				indx_list;	
	int				link_nb;
	struct s_room	*next;
	struct s_room	*link_room;
}                       t_room;

/*typedef struct      s_data
{
	int     		ants_nb;
	int				size_array;
	int				hash_index;
	struct s_room  	**tab_rooms;
}                   t_data;
*/
typedef struct	s_avl
{
	char            *rooms_name;
	int             coord_x;
	int             coord_y;
	int				height;
	char            pos;
	struct	s_avl	*left;
	struct  s_avl	*right;
	struct  s_adj   *links;
}				t_avl;

typedef struct		s_adj
{
	t_avl			*adj;
	struct s_adj	*next;
}					t_adj;

typedef struct		s_data
{
	char            *room;
	int             x;
	int             y;
	char            var;
}					t_data;

t_avl		*ft_new_node(t_data data);
int			ft_height(t_avl *node);
int			ft_max(int a, int b);
void		ft_add_edge(t_avl *tree, char *r1, char *r2);
void		ft_balance(t_avl **tree, t_data data);
void		ft_insert_node(t_avl **tree, t_data data);
void		ft_print_tree(t_avl *tree, char c);
//int		ft_check_nbr(char *line, int i);
//int		ft_read_n_ants(t_data  *node);
//int		ft_hash_function(char *str, int size_array);
//t_data	*ft_stock_file();
void    ft_error_function();
//int		ft_stock_lines(t_stock_file *file);
//t_data  *ft_stock_rooms(t_stock_file *file, int nb_of_line);
//int     ft_prime(int nb);
//t_data	*ft_alloc_big_tab(int size);
//void    ft_add_add_links(t_data *node);


#endif
