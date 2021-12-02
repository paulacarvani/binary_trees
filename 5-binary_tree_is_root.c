#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a given node is a root
 * @node: Node to check if is a root
 * Return: 1 if node is a root and 0 if is NULL or otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->parent == NULL)
		return (1);
	else
		return (0);
}
