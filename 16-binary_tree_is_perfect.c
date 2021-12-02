#include "binary_trees.h"

/**
 * equals_height - balance_height
 * @tree: balanced tree
 * Return: A int
 */
int equals_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + (MAX(equals_height(tree->left), equals_height(tree->right))));
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
	return (equals_height(tree->left) - equals_height(tree->right));
}

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

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: Tree to be checked if is a perfect tree
 * Return: Return 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_full = 0;
	int is_balance = 0;

	if (tree == NULL)
	{
		return (0);
	}
	is_full = binary_tree_is_full(tree);
	is_balance = binary_tree_balance(tree);
	if (is_balance == 0)
	{
		is_balance = 1;
	}
	else
	{
		is_balance = 0;
	}
	return (is_full * is_balance);
}
