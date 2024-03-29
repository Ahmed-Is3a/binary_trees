#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 *
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node, or NULL if node is NULL,
 * the parent is NULL, the grandparent is NULL, or node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	grandparent = node->parent->parent;

	if (grandparent->left == node->parent)
	{
		if (grandparent->right != NULL)
			return (grandparent->right);
	}
	else
	{
		if (grandparent->left != NULL)
			return (grandparent->left);
	}

	return (NULL);
}
