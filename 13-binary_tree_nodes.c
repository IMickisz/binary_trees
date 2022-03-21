#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the number of nodes
 * in a binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (tree->left == NULL && tree->right != NULL)
		return (1 + binary_tree_nodes(tree->right));
	else if (tree->left != NULL && tree->right == NULL)
		return  (1 + binary_tree_nodes(tree->left));
	else if (tree->left != NULL && tree->right != NULL)
		return (1 + binary_tree_nodes(tree->right)
			+ binary_tree_nodes(tree->left));
	else
		return binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right);
}
