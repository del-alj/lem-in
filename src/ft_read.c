#include "../includes/ft_lem_in.h"

void	ft_print_link(t_avl *tree , char c)
{
	if (tree)
	{
		ft_printf("{%s} :\t", tree->rooms_name);
		while (tree->adj)
		{
			ft_printf("[%s]", tree->adj->n_link->rooms_name);
			tree->adj = tree->adj->next;
		}
		ft_printf("\n");
		ft_print_link(tree->right, 'r');
		ft_print_link(tree->left, 'l');
	}
}

int		main()
{
	t_avl	*tree;
//	char	*char_tab[] = {"5", "2", "3", "4", "5"};
	char    *char_tab[] = {"2", "1", "5", "6", "8"};
	int i = 0;
	t_data data;

	data.x = 0;
	data.y = 0;
	data.var = 'a';
	data.room = "3";
	tree = ft_new_node(data);
	while (i < 5)
	{
		data.room = ft_strdup(char_tab[i]);
		ft_insert_node(&tree, data);
		i++;
	}
//	ft_print_tree(tree, 'o');
	char    *char_tab1[]= {"6", "5", "3", "6", "6", "2", "2"};
	char    *char_tab2[]= {"5", "6", "2", "5", "5", "3", "1"};


	i = 7;
	while (i--)
		ft_add_edge(tree, char_tab2[i], char_tab1[i]);
	ft_print_link(tree, 'o');
	return (0);
}

