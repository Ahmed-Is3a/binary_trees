#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth - Measure the depth of a node in a binary tree
 *
 * @tree: A pointer to the node whose depth is to be measured
 *
 * Return: The depth of the node, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    size_t depth_left = binary_tree_depth(tree->left);
    size_t depth_right = binary_tree_depth(tree->right);

    // Add 1 to account for the current node
    return 1 + (depth_left > depth_right ? depth_left : depth_right);
}