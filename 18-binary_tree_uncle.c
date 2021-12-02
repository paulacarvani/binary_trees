#include "binary_trees.h"

/**
 * binary_tree_uncle - function that checks a node's uncle
 * @node: Tree to check its uncle
 * Return: Pointer to the uncle or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
