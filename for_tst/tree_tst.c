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

void	ft_print_tree(t_avl *tree, char c)
{
	if (tree == NULL)
		return ;
	printf("%d - %c -> %d\n", tree->key, c, tree->height);
	ft_print_tree(tree->right, 'r');
	ft_print_tree(tree->left, 'l');
}

t_avl	*ft_new_node(int key)
{
	t_avl	*node;

	if (!(node = (t_avl*)malloc(sizeof(t_avl))))
		return (NULL);
	node->key = key;
	node->height = 1;
	node->left = NULL;
	node->right= NULL;
	return (node);
}

int		ft_height(t_avl *node)
{
	if (node)
		return (node->height);
	else
		return (0);

}

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

t_avl	*ft_left_retation(t_avl *tree)
{
	t_avl *root;

	root = tree->left;
	tree->left = root->right;
	root->right = tree;
	
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->height = ft_max(ft_height(root->left), ft_height(root->right)) + 1;
	return (root);
}

t_avl   *ft_right_retation(t_avl *tree)
{
	t_avl *root;

	root = tree->right;
	tree->right = root->left;
	root->left = tree;
	tree->height = ft_max(ft_height(tree->left), ft_height(tree->right)) + 1;
	root->height = ft_max(ft_height(root->left), ft_height(root->right)) + 1;
	return (root);
}


void	ft_insert_node(t_avl **tree, int key)
{
	int		balance;

	if ((*tree)->left && key < (*tree)->key)
		ft_insert_node(&(*tree)->left, key);
	else if ((*tree)->right && key > (*tree)->key)
		ft_insert_node(&(*tree)->right, key);
	if ((*tree)->left == NULL && key < (*tree)->key)
		(*tree)->left = ft_new_node(key);
	else if ((*tree)->right == NULL && key > (*tree)->key)
		(*tree)->right = ft_new_node(key);
	(*tree)->height = 1 + ft_max(ft_height((*tree)->left), ft_height((*tree)->right));
	if ((*tree))
		balance = ft_height((*tree)->left) - ft_height((*tree)->right);
	else
		balance = 0;
	if (balance < -1)
		(*tree)  = ft_right_retation((*tree));
	else if (balance > 1)
		 (*tree) = ft_left_retation((*tree));
}
int	main()
{
	int	tab[6] = {1, 6, 7, 8, 9, 10};
	t_avl   *tree;
	int i = 6;
	tree = ft_new_node(11);
	ft_print_tree(tree, 'b');
	while (i)
	{
		ft_insert_node(&tree, tab[i - 1]);
		i--;
	}
	// print tree
	ft_print_tree(tree, 'o');
	return (0);
}
