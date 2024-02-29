#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: The height of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise (including if tree is NULL)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    if (left_height != right_height)
        return (0);

    return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
}