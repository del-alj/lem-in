#include "../includes/ft_lem_in.h"

void	ft_print_link(t_avl *tree , char c)
{
	if (tree)
	{
		ft_printf("{%s} :\t", tree->rooms_name);
		while (tree->adj != NULL)
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
	char    *char_tab[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	int i = 0;
	t_data data;

	data.x = 0;
	data.y = 0;
	data.var = 'a';
	data.room = "0";
	tree = ft_new_node(data);
	while (i < 10)
	{
		data.room = ft_strdup(char_tab[i]);
		ft_insert_node(&tree, data);
		i++;
	}
//	ft_print_tree(tree, 'o');
//	char    *char_tab1[]= {"0", "2", "3", "4", "5", "1", "6", "7", "8", "9", "10"};
//	char    *char_tab2[]= {"10", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0"};

	char    *char_tab1[]= {"0", "2", "3", "4", "5", "1", "6", "7", "8", "9", "10",
							"10", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0"};
	char    *char_tab2[]= {"10", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0",
							"1", "3", "4", "5", "7", "7", "8", "9", "10", "2", "3"};


	i = 22;
	while (i--)
		ft_add_edge(&tree, char_tab2[i], char_tab1[i]);
	ft_print_link(tree, 'o');
	return (0);
}

