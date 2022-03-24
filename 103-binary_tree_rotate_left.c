#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that rotate two nodes in binary tree
 * @tree: pointer to the root node
 * Return: return a pointer to the new node once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *first;

	if (tree == NULL)
		return (NULL);
	first = tree->right;
	tree->right = first->left;
	if (first->left != NULL)
		first->left->parent = tree;
	first->parent = tree->parent;
	first->left = tree;
	tree->parent = first;
	return (first);
}
