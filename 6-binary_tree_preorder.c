#include "binary_trees.h"

/**
 * binary_tree_preorder - function that goes through a binary tree
 * @tree: Tree to be checked
 * @func: int function printer
 * Return: It is a void function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
