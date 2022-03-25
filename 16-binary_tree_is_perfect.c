#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree.
 * @tree: pointer
 * Return: 1,0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);

	counter = binary_recursion_depth(tree);
	return (perfect_tree(tree, counter, 0));
}

/**
 * perfect_tree - function that find if a tree is perfect
 * @tree: pointer is a node
 * @counter: the counter
 * @level: The level where is the visit node
 * Return: 1.
 */

int perfect_tree(const binary_tree_t *tree, size_t counter, int level)
{
	if (tree->left == NULL && tree->right == NULL)
	{
		if (level == (int)counter)
			return (1);
		return (0);
	}
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (perfect_tree(tree->left, counter, level + 1) == 1 &&
		perfect_tree(tree->right, counter, level + 1) == 1)
		return (1);
	else
		return (0);
}

/**
 * binary_recursion_depth - function that measures the depth
 * @tree: pointer
 * Return: NULL
 */
size_t binary_recursion_depth(const binary_tree_t *tree)
{
	if (tree->left)
		return (1 + binary_recursion_depth(tree->left));
	return (0);
}
