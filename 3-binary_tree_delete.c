#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary
 * @tree: Pointer
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;

	free(tree);
