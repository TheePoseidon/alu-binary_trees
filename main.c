#include "binary_trees.h"
#include <stdio.h>

int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    if (root == NULL)
        return (1);

    printf("root.n = %d\n", root->n);
    printf("root.parent = %p\n", (void *)root->parent);
    printf("root.left = %p\n", (void *)root->left);
    printf("root.right = %p\n", (void *)root->right);

    free(root);
    return (0);
}