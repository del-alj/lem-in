/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:39:05 by del-alj           #+#    #+#             */
/*   Updated: 2020/02/18 15:55:26 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

#include <stdio.h>
# include "../libftprintf/headers/libft.h"
# include "../libftprintf/headers/ft_printf.h"

typedef struct	s_avl
{
	char            *rooms_name;
	int             coord_x;
	int             coord_y;
	int				height;
	char            pos;
	struct	s_avl	*left;
	struct  s_avl	*right;
	struct  s_adj   *adj;
}				t_avl;

typedef struct		s_adj
{
	t_avl			*n_link;
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
void		ft_add_edge(t_avl **tree, char *r1, char *r2);
void		ft_balance(t_avl **tree, t_data data);
void		ft_insert_node(t_avl **tree, t_data data);
void		ft_print_tree(t_avl *tree, char c);
void		ft_error_function(t_avl *tree);

/*
** file : parser.c
*/

int	ft_get_room_info(char *str, int i, t_data *data);
int	ft_check_room(char *str, t_data *data);

/*
** file : parser_tools.c
*/

char 	*ft_escap_whitspace(char *str);
int 	ft_isspace(int c);


#endif
