#include "binary_trees.h"

/**
 * binary_tree_leaves - count the number of node as a leave
 * @tree: pointer to the root of the tree to count the number of leaves
 * Return: 0 if tree is NULL else return size
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else
		return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
