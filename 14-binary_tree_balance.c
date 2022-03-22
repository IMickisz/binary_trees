#include "binary_trees.h"
#include <stdio.h>
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
 * comper - recursion for comper
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

/**
 * binary_tree_balance - function that measures the balance of a binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		right = binary_tree_height(tree->right) + 1;
	return (left - right);
}
