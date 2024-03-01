#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Set 'new_root' to the right child of the tree */
	new_root = tree->right;

	/* Update the right child of the tree to the left child of 'new_root' */
	tree->right = new_root->left;

	/* Update the parent pointer of the new right child (if it exists) */
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Update the parent pointer of 'new_root' */
	new_root->parent = tree->parent;

	/* If the tree had a parent, update its child pointer to 'new_root' */
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}

	/* Update the parent pointer of the tree to 'new_root' */
	tree->parent = new_root;

	/* Set the left child of 'new_root' to the original tree */
	new_root->left = tree;

	return (new_root);
}
