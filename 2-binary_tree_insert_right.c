#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node to the right child
 * @parent: pointer to the node to insert
 * @value: the value to store in the new node
 * Return: Point to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	if (parent->right == NULL)
		parent->right = binary_tree_node(parent, value);
	else
	{
		tmp = parent->right;
		parent->right = binary_tree_node(parent, value);
		tmp->parent = parent->right;
		parent->right->right = tmp;
	}
	return (parent->right);
}
