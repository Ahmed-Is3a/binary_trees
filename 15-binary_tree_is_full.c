#include "binary_trees.h"

/**
 * binary_tree_is_full - Check if a binary tree is full
 *
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is full, 0 otherwise (including if tree is NULL)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    if ((tree->left == NULL && tree->right != NULL) ||
        (tree->left != NULL && tree->right == NULL))
    {
        return 0; // One child is NULL, not full
    }

    // Recursively check left and right subtrees
    return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
}