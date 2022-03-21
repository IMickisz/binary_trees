#include "binary_trees.h"

/**
 * binary_tree_depth -  function that measures the size of a binary tree
 * @tree: pointer to the node to measure the size
 * Return: the size or if tree is NULL 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right);
	return (size);
}
