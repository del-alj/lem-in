#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_avl
{
	int				key;
	int				height;
	struct	s_avl	*left;
	struct  s_avl	*right;
}				t_avl;

t_avl	*ft_new_node(int key)
{
	t_avl	*node;

	if (!(node = (t_avl*)malloc(sizeof(t_avl))))
		return (NULL);
	node->key = key;
	node->height = 0;
	node->left = NULL;
	node->right= NULL;
	return (node);
}

void   ft_insert_node(t_avl *tree, int key)
{
	t_avl *current;

	current = tree;
	while (current)
	{
		if (current->left == NULL && key < current->key)
		{
			current->left = ft_new_node(key);
			break ;
		}
		if (current->right == NULL && key > current->key)
		{
			current->right = ft_new_node(key);
			break ;
		}
		if (key < current->key)
			current = current->left;
		else if (key > current->key)
			current = current->right;
		else
			break ;
	}
}

t_avl	*ft_right_retation(t_avl *tree)
{
	t_avl *root;
	
	root = tree->left;
	tree->left = NULL;
	root->right = tree;
	return (root);
}

t_avl   *ft_left_retation(t_avl *tree)
{
	t_avl *root;

	root = tree->right;
	tree->right = NULL;
	root->left = tree;
	return (root);
}

void	ft_print_tree(t_avl *tree)
{
	if (tree == NULL)
		return ;
	printf("%d\n", tree->key);
	ft_print_tree(tree->right);
	ft_print_tree(tree->left);
}

int	main()
{
	int	tab[2] = {11, 6};
	t_avl   *tree;
	int i = 2;
	tree = ft_new_node(1);
	while (i--)
	{
		ft_insert_node(tree, tab[i]);
		//how to calcul balence
		
	}
	//tree = ft_left_retation(tree);
	//tree = ft_right_retation(tree);
	ft_print_tree(tree);
	return (0);
}
