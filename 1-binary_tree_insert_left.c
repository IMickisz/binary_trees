#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node to the left child
 * @parent: pointer to the node to insert
 * @value: the value to store in the new node
 * Return: Point to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node, *tmp;

	if (parent == NULL)
		return NULL;

	if (parent->left == NULL)
	{
		new_node = binary_tree_node(parent->left, value);
		parent->left = new_node;
	}
	else
	{
		tmp = parent->left;
		new_node = binary_tree_node(parent->left, value);
		new_node->left = tmp;
		new_node->left->parent = new_node;
	}
	return new_node;
}
