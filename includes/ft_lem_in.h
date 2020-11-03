/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:39:05 by del-alj           #+#    #+#             */
/*   Updated: 2020/11/03 10:31:54 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include <stdio.h>
# include "../libft/headers/libft.h"

# define BUFF_READ 10000

typedef struct		s_avl
{
	char			*name;
	int				id;
	t_point			cord;
	int				height;
	int				taken;
	struct s_avl	*left;
	struct s_avl	*right;
	struct s_adj	*adj;
}					t_avl;

typedef struct		s_adj
{
	int				cap;
	t_avl			*edge;
	t_avl			*prev;
	struct s_adj	*next;
}					t_adj;

typedef struct		s_data
{
	int		x;
	int		y;
	char	*room;
	char	*adj_room;
	char	var;
}					t_data;

typedef	struct		s_box
{
	t_avl	*tree;
	t_avl	*start;
	t_avl	*end;
	int		ports;
	int		ants_nbr;
	int		vertics_num;
}					t_box;

/*
** len : length of the path
** path_ant_nbr: the number of ants that will take this path
** list: list that contains the vertics names and \
** the ant number that's in that vertics
*/

typedef struct		s_path
{
	int				len;
	int				path_ant_nbr;
	t_list_simple	*list;
}					t_path;

typedef struct		s_queue
{
	t_adj	*head;
	t_adj	*front;
	t_adj	*rear;
}					t_queue;

typedef struct		s_bfs_data
{
	t_queue *q;
	int		*level;
	int		*visited;
}					t_bfs_data;

/*
**	file : ft_max.c
*/

int					ft_max(int a, int b);

/*
** file : ft_add_egde.c
*/

void				ft_add_edge(t_avl **tree, char *r1, char *r2);

/*
**	file : ft_balance.c
*/

void				ft_balance(t_avl **tree, t_data data);

/*
** file : parser.c
*/
int					ft_update_next_start(char *str, int *idx, int stop);
int					ft_read_input(t_box *head, char **buff);

/*
** file : ft_error_function.c
*/

void				ft_free_data(t_bfs_data dt);
void				ft_free_queue(t_queue **q);
void				ft_free_tree(t_avl *tree);
void				ft_error_function(t_avl *tree, char *str);

/*
**	ft_dfs.c
*/

int					can_i_pass(t_avl *prev, t_avl *u, t_adj *adj);
int					dfs(t_avl *prev, t_avl *u, t_avl *v, int *level);
int					ft_get_the_max_flow(t_box *head, t_path **paths);

/*
**	file : bfs.c
*/

int					bfs(t_box *box, t_avl *start, t_bfs_data *data);
int					ft_bfs_extentions(t_box *box, t_bfs_data *data, \
										t_adj *cur_e, t_avl *curr_vertex);
t_queue				*ft_init_queue(t_avl *start);
void				enqueue(t_queue *q, t_avl *node, int cap);
t_avl				*dequeue(t_queue *q);

/*
**	file : make_group.c
*/

t_path				*ft_make_group(t_box *head, int nb_path, int *score);
int					ft_score(t_box *head, int nb_path, \
								int *score, t_path **paths);
void				ft_free_path_group(t_path **paths);
void				ft_add_to_path(t_path *path, char *name);

/*
**	file : ft_simple_lstdel.c
*/

void				ft_simple_lstdel(t_list_simple **alst);

/*
**	file : ft_main.c
*/

void				ft_count_bottleneck_edges(t_box *head);
int					ft_len_adj(t_adj *list);

/*
**	file : save_info.c
*/

int					ft_get_room_info(char *str, int i, t_data *data);
int					ft_get_edge_info(char *str, int i, t_data *data);
int					ft_check_line(char *str, t_data *data, t_box *head);
void				ft_add_room(t_box *head, t_data *data, int bol, char **str);
int					ft_save_rooms_and_edges(int index, char *str, \
												int stop, t_box *head);

/*
**	file : ft_insert_node.c
*/

int					ft_height(t_avl *node);
void				ft_if_start_end(t_avl *node, t_data data, t_box *box);
t_avl				*ft_new_node(t_data data);
void				ft_insert_node(t_avl **tree, t_data data, t_box *box);

/*
**	file : ft_pass_ants.c
*/

void				ft_pass_ants(t_path *paths, int nb_paths, int nbr_of_ants);

/*
**	file : ft_print_ant.c
*/

void				count_ants_in_path(int maxflow, \
										t_path *paths, \
										int nbr_of_ants);
void				ft_print_ant(int i, char *str);

#endif
