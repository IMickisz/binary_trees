#include "binary_trees.h"

/**
 * findADepth - function that return the depth of the leftmost leaf
 * @tree: pointer to the root node of the tree to check
 * Return: depth of the most leftmost leaf
 */

int findADepth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * isPerfectRec - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: the depth of the leftmost leaf
 * @level: the level of the node
 * Return: if tree is NULL, your function must return 0
 */

int isPerfectRec(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level)
			return (1);
		else
			return (0);
	}
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (isPerfectRec(tree->left, depth, level + 1) &&
		isPerfectRec(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: if tree is NULL, your function must return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	depth = findADepth(tree);
	return (isPerfectRec(tree, depth, 0));
}
