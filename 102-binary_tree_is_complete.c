#include "binary_trees.h"

/**
 * count_nodes - function that counts the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: the number of nodes
 */

int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @i: index
 * @count: number of nodes
 * Return: 1 if true or 0 if false
 */

int is_complete(const binary_tree_t *tree, unsigned int i, unsigned int count)
{
	if (tree == NULL)
		return (1);
	if (i >= count)
		return (0);
	return (is_complete(tree->left, 2 * i + 1, count) &&
		is_complete(tree->right, 2 * i + 2, count));
}

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true  or 0 if false
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count;

	if (tree == NULL)
		return (0);
	count = count_nodes(tree);
	return (is_complete(tree, 0, count));
}
