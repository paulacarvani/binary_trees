#include "binary_trees.h"

/**
 * balance_height - balance_height
 * @tree: balanced tree
 * Return: A int
 */
int balance_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + (MAX(balance_height(tree->left), balance_height(tree->right))));
}

/**
 * binary_tree_balance - function that measures the balance
 * @tree: Tree to be balanced
 * Return: Balanced int
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (balance_height(tree->left) - balance_height(tree->right));
}
