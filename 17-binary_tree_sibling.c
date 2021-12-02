#include "binary_trees.h"

/**
 * binary_tree_sibling - function that checks a node's sibling
 * @node: Tree to check its sibling
 * Return: Pointer to the sibling or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
