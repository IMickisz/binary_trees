#include "binary_trees.h"

void print_level(const binary_tree_t *tree, int level, void (*func)(int));
/**
 * height - functions that returns the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: the height of the binary tree
 */

int height(const binary_tree_t *tree)
{
	int leftheight, rightheight;

	if (tree == NULL)
		return (0);
	leftheight = height(tree->left);
	rightheight = height(tree->right);
	if (leftheight > rightheight)
		return (leftheight + 1);
	else
		return (rightheight + 1);
}

/**
 * print_level_order - functions that print the tree using the level-order.
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: Nothing
 */

void print_level_order(const binary_tree_t *tree, void(*func)(int))
{
	int h = height(tree) + 1, i;

	for (i = 1; i <= h; i++)
		print_level(tree, i, func);
}

/**
 * print_level - function that prints the values of the current level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level to print
 * Return: Nothing (if tree or func is NULL, do nothing)
 */

void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - function that goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: Nothing (if tree or func is NULL, do nothing)
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	print_level_order(tree, func);
}
