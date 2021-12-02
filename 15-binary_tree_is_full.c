#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: Tree to check if is full
 * Return: If tree is NULL return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL || tree->right != NULL)
	{
		return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));
	}
	else
	{
		return (1);
	}
}
