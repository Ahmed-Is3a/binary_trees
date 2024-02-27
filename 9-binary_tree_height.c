#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 *
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: The height of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    // Add 1 to account for the current node
    return 1 + (left_height > right_height ? left_height : right_height);
}