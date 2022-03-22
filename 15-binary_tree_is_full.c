#include "binary_trees.h"

/**
 * one_child - count the number of node with one child
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

int one_child(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (tree->left == NULL && tree->right != NULL)
		return (1 + one_child(tree->right));
	else if (tree->left != NULL && tree->right == NULL)
		return  (1 + one_child(tree->left));
	else
		return one_child(tree->left) +
			one_child(tree->right);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int count;

	if (tree == NULL)
		return (0);
	count = one_child(tree);
	if (count != 0)
		return (0);
	return (1);
}
