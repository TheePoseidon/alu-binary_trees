#include "binary_trees.h"
#include <stdio.h>

int main(void)
{
    binary_tree_t *root;
    binary_tree_t *first_left;
    binary_tree_t *second_left;

    /* Step 1: create root */
    root = binary_tree_node(NULL, 98);
    if (root == NULL)
        return (1);

    /* Step 2: insert first left child */
    first_left = binary_tree_insert_left(root, 12);
    if (first_left == NULL)
        return (1);

    printf("After first insert:\n");
    printf("root.left.n = %d\n", root->left->n);
    printf("first_left.parent.n = %d\n", first_left->parent->n);

    /* Step 3: insert ANOTHER left child on root */
    /* Expected: second_left takes root->left's spot, */
    /* and first_left becomes second_left's left child */
    second_left = binary_tree_insert_left(root, 7);
    if (second_left == NULL)
        return (1);

    printf("\nAfter second insert:\n");
    printf("root.left.n = %d (expect 7)\n", root->left->n);
    printf("root.left.left.n = %d (expect 12)\n", root->left->left->n);
    printf("first_left.parent.n = %d (expect 7)\n", first_left->parent->n);

    /* Step 4: NULL parent should return NULL */
    if (binary_tree_insert_left(NULL, 99) == NULL)
        printf("\nNULL parent correctly returned NULL\n");

    free(first_left);
    free(second_left);
    free(root);

    return (0);
}