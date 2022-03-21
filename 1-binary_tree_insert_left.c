#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node to the left child
 * @parent: pointer to the node to insert
 * @value: the value to store in the new node
 * Return: Point to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *tmp;

	if (parent == NULL)
		return NULL;

	if (parent->left == NULL)
		parent->left = binary_tree_node(parent, value);
	else
	{
		tmp = parent->left;
		parent->left = binary_tree_node(parent, value);
		tmp->parent = parent->left;
		parent->left->left = tmp;
	}
	return (parent->left);
}
