#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that rotate right two nodes in binary tree
 * @tree: pointer to the root node
 * Return: return a pointer to the new node once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *first;

	if (tree == NULL)
		return (NULL);
	first = tree->left;
	tree->left = first->right;
	if (first->right != NULL)
		first->right->parent = tree;
	first->parent = tree->parent;
	first->right = tree;
	tree->parent = first;
	return (first);
}
