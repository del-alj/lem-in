
#include "ft_lem_in.h"

typedef struct		s_tree
{
	char            *str;
    struct s_tree   *left;
    struct s_tree   *right;
    int             height;
}					t_tree;

void    ft_add_children(t_tree *node, int valeur)
{
    if (valeur > node->height && node->right != NULL)
    {
        node = node->right; 
        ft_add_tree(node->right, valeur);
    }
    if (valeur < node->height && node->left != NULL)
    {
        node = node->left;
        ft_add_tree(node->left, valeur);
    }
}

void    ft_add_tree(t_tree *node, char *line)
{
    int valeur;

    valeur = ft_strcmp(node->str, line);
    if (valeur == 0)
        ft_error_function();
    ft_add_children(node, valeur);
}
