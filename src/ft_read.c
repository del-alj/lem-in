#include "../includes/ft_lem_in.h"

void	ft_print_link(t_avl *tree , char c)
{
	if (tree)
	{
		ft_printf("|%s| \n", tree->rooms_name);
		while (tree->links)
		{
			printf("|%s| --- |%c|", tree->links->adj->rooms_name, c);
			tree->links = tree->links->next;
		}
		ft_printf(" |%c|etab next \n", c);
		ft_print_link(tree->right, 'r');
		ft_print_link(tree->left, 'l');
	}
}

int		main()
{
	t_avl	*tree;
//	char	*char_tab[] = {"5", "2", "3", "4", "5"};
	char    *char_tab[] = {"2", "1"};
	int i = 0;
	t_data data;

	data.x = 0;
	data.y = 0;
	data.var = 'a';
	data.room = "3";
	tree = ft_new_node(data);
	while (i < 2)
	{
		data.room = ft_strdup(char_tab[i]);
		ft_insert_node(&tree, data);
		i++;
	}
//	ft_print_tree(tree, 'o');
	char    *char_tab1[] = {"2", "3", "1"};
	char    *char_tab2[] = { "1", "2", "3"};
	i = 3;
	while (i--)
		ft_add_edge(tree, char_tab2[i], char_tab1[i]);
	ft_print_link(tree, 'o');
	return (0);
}
