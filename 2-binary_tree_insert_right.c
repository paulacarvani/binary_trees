#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts
 * @parent: The parent tree
 * @value: the tree value
 * Return: Inserted tree
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->n = value;
	if (parent->right != NULL)
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
		parent->right = new_node;
	}
	else
	{
		parent->right = new_node;
		new_node->right = NULL;
	}
	return (new_node);
}
