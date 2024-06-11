#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

// Define a generic type for keys and values in the BST.
typedef void *BSTKey;
typedef void *BSTValue;

// Declare function pointer for comparing the keys.
typedef int (*BSTCompareFunc)(BSTKey, BSTKey);

// Structure for a binary search tree node.
typedef struct BSTNode
{
    BSTKey key;
    BSTValue value;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Structure for the binary search tree.
typedef struct BST
{
    BSTNode *root;
    BSTCompareFunc compare;
} BST;

BST *bst_create(BSTCompareFunc compare);

void bst_destroy(BST *tree);

bool bst_insert(BST *tree, BSTKey key, BSTValue value);

BSTValue bst_find(BST *tree, BSTKey key);

bool bst_remove(BST *tree, BSTKey key);

void bst_inorder_traversal(BST *tree, void (*visit)(BSTNode *node));

#endif