#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node if node, parent or if node has
 * no sibling return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->n == node->parent->left->n)
		return (node->parent->right);
	else if (node->n == node->parent->right->n)
		return (node->parent->left);
	else
		return (NULL);
}
