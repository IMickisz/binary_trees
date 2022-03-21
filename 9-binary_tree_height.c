#include "binary_trees.h"

/**
 * max - return the max number
 * @a: integer
 * @b: integer
 * Return: a or b
*/

int max(int a, int b)
{
        if (a > b)
                return (a);
        else
                return (b);
}

/**
 * minus - return the -1
 * @tree: the magnus variable
 * Return: result minus 1
 */

size_t comper(const binary_tree_t *tree)
{
	size_t left, right;
	int magnus;

	if (tree == NULL)
		return (0);

	left = comper(tree->left);
	right = comper(tree->right);
	magnus = max(left, right) + 1;
	return (magnus);
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (comper(tree) - 1);
}
