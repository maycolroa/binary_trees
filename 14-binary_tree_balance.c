#include "binary_trees.h"

/**
 * binary_tree_new_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: Binary tree height and 0 If tree is NULL
 */
size_t binary_tree_new_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);

	left = 1 + binary_tree_new_height(tree->left);
	right = 1 + binary_tree_new_height(tree->right);

	if (left > right)
		return (left);

	return (right);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree measure the balance factor
 * Return: balance factor and 0 If tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	left = binary_tree_new_height(tree->left) + 1;
	right = binary_tree_new_height(tree->right) + 1;

	return (left - right);
}
