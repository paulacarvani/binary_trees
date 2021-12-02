#include "binary_trees.h"

/**
 * binary_trees_ancestor - function to inquiry for a nodes common ancestors
 * @first: Node #1
 * @second: Node #2
 * Return: Common ancestor or NULL if there is not
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth_first = 0;
	size_t depth_second = 0;
	const binary_tree_t *tmp_first = NULL;
	const binary_tree_t *tmp_second = NULL;
	const binary_tree_t *result = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	tmp_first = first;
	tmp_second = second;
	depth_first = binary_tree_depth(first); /*Measure Depth*/
	depth_second = binary_tree_depth(second); /*Measure Depth*/
	if (depth_first > depth_second) /*ancestor_tracker(first, second)*/
	{
		result = ancestors_tracker(tmp_first, tmp_second);
		if (result == NULL)
			return (NULL);
		return ((binary_tree_t *)result);
	}
	if (depth_second > depth_first)
	{
		result = ancestors_tracker(tmp_second, tmp_first);
		if (result == NULL)
			return (NULL);
		return ((binary_tree_t *)result);
	}
	else
	{
		while (tmp_second != NULL && tmp_first != NULL)
		{
			tmp_first = tmp_first->parent;
			tmp_second = tmp_second->parent;
			if (tmp_first == tmp_second)
				return ((binary_tree_t *)tmp_first);
		}
	}
	return (NULL);
}

/**
 * binary_tree_depth - function that measures the depth of a node
 * @tree: Tree to gget depth
 * Return: Tree depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}

/**
 * ancestors_tracker - function that tracks ancestor based on depth
 * @biggest: Deeper node
 * @smallest: node to compare
 * Return: ancestor or NULL if there is not
 */
binary_tree_t *ancestors_tracker(const binary_tree_t *biggest,
	const binary_tree_t *smallest)
{
	size_t i = 0;
	size_t depth_biggest = 0;
	size_t depth_smallest = 0;
	size_t depth_balance = 0;
	const binary_tree_t *tmp_biggest = biggest;
	const binary_tree_t *tmp_smallest = smallest;

	depth_biggest = binary_tree_depth(biggest); /*Measure Depth*/
	depth_smallest = binary_tree_depth(smallest); /*Measure Depth*/
	depth_balance = depth_biggest - depth_smallest;

	while (i < depth_balance)
	{
		tmp_biggest = tmp_biggest->parent;
		i++;
		if (tmp_biggest == smallest) /*Validates third case TEST*/
			return ((binary_tree_t *)smallest);
	}
		while (tmp_smallest != NULL && tmp_biggest != NULL)
		{
			tmp_biggest = tmp_biggest->parent;
			tmp_smallest = tmp_smallest->parent;
			if (tmp_biggest == tmp_smallest)
				return ((binary_tree_t *)tmp_biggest);
		}
		return (NULL);
}
