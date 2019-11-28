/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_linkd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:19:15 by del-alj           #+#    #+#             */
/*   Updated: 2019/11/28 15:35:44 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   typedef	struct		s_tt
   {
   char			*str;
   struct  s_tt	*next;


   }					t_tt;
   */

typedef struct  	s_list_rooms
{
	struct s_node	*list;
	struct  s_list	*next;
}					t_list_rooms;

typedef struct		s_node
{
	int				coord_x;
	int				coord_y;
	char			*rooms_name;
	char			*pos;
	int				link_nb;
}					t_node;
/*
   void	ft_push_node(t_tt *head, char *str)
   {
   t_tt	*current = head;
   while (current->next != NULL)
   {
   current = current->next;
   }
   current->next = malloc(sizeof(t_tt));
   current->next->str = strdup(str);
   current->next->next = NULL;
   }
   */

int		ft_creat_node(char	*str)
{
		
	return (1);
}

int    ft_push_node(t_list_rooms **head, t_node *list, char *pos)
{
	t_list_rooms    *new_node;

	if (!(new_node = (t_list_rooms*)malloc(sizeof(t_list_rooms))))
		return (0);
		new_node->list->coord_x = list->coord_x;
		new_node->list->coord_y = list->coord_y;
		new_node->list->rooms_name = ft_strdup(list->rooms_name);
		if (pos)
			new_node->list->pos = ft_strdup(pos);
	new_node->next = *head;
	*head = new_node;
	return (1);
}

int	ft_new_list(t_list_rooms **head, t_node *list)
{
	

}
int		main()
{
	t_list_rooms	*head = NULL;
	t_list_rooms	*list = NULL;

	list = (t_list_rooms*)malloc(sizeof(t_list_rooms));
	head = list;
//	ft_new_list(t_list_rooms **head, list);
	








	/*while (list != NULL)
	{
		printf("%s\n", list->str);
		list = list->next;	
	}*/
	return (0);
}
