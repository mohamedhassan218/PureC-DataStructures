#include "bst.h"
#include <stdlib.h>

// FIRST: MEET THE HELPER FUNCTIONs

// Helper function to create a new node.
static BSTNode *bst_create_node(BSTKey key, BSTValue value)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (node)
    {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

// Helper function to destroy all nodes in the tree.
static void bst_destroy_nodes(BSTNode *node)
{
    if (node)
    {
        bst_destroy_nodes(node->left);
        bst_destroy_nodes(node->right);
        free(node);
    }
}

// Helper function to insert a node in the tree.
static BSTNode *bst_insert_node(BSTNode *node, BSTKey key, BSTValue value, BSTCompareFunc compare)
{
    if (!node)
        return bst_create_node(key, value);
    int cmp = compare(key, node->key);
    if (cmp < 0)
        node->left = bst_insert_node(node->left, key, value, compare);
    else if (cmp > 0)
        node->right = bst_insert_node(node->right, key, value, compare);
    else
        node->value = value;
    return node;
}

// Helper function to find a specific node in the tree.
static BSTNode *bst_find_node(BSTNode *node, BSTKey key, BSTCompareFunc compare)
{
    if (!node)
        return NULL;
    int cmp = compare(key, node->key);
    if (cmp < 0)
        return bst_find_node(node->left, key, compare);
    else if (cmp > 0)
        return bst_find_node(node->right, key, compare);
    else
        return node;
}

// Helper function to find the minimum node in the subtree.
static BSTNode *bst_find_min(BSTNode *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

// Helper function to remove a specific node from our tree.
static BSTNode *bst_remove_node(BSTNode *node, BSTKey key, BSTCompareFunc compare)
{
    if (!node)
        return NULL;

    int cmp = compare(key, node->key);
    if (cmp < 0)
        node->left = bst_remove_node(node->left, key, compare);
    else if (cmp > 0)
        node->right = bst_remove_node(node->right, key, compare);
    else
    {
        // If node has only right child(s), it's right child takes its place.
        if (!node->left)
        {
            BSTNode *rightChild = node->right;
            free(node);
            return rightChild;
        }
        // If node has only left child(s), it's left child takes its place.
        else if (!node->right)
        {
            BSTNode *leftChild = node->left;
            free(node);
            return leftChild;
        }
        else
        {
            // Node with two children: get the inorder successor (smallest in the right subtree).
            // We made the inorder succesor to take the node place.
            BSTNode *minRight = bst_find_min(node->right);
            node->key = minRight->key;
            node->value = minRight->value;
            node->right = bst_remove_node(node->right, minRight->key, compare);
        }
    }
    return node;
}

// Helper function to visit our tree in-order.
static void inorder(BSTNode *node)
{
    if (node)
    {
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
}

// NOW LET'S UTILIZE OUR HELPERS IN THE MAIN FUNCTIONs

// Function to create new tree.
BST *bst_create(BSTCompareFunc compare)
{
    BST *tree = (BST *)malloc(sizeof(BST));
    if (tree)
    {
        tree->root = NULL;
        tree->compare = compare;
    }
    return tree;
}

// Function to destroy the whole tree.
void bst_destroy(BST *tree)
{
    if (tree)
    {
        bst_destroy_nodes(tree->root);
        free(tree);
    }
}

// Function to insert a key-value pair into the tree.
bool bst_insert(BST *tree, BSTKey key, BSTValue value)
{
    if (!tree)
        return false;
    tree->root = bst_insert_node(tree->root, key, value, tree->compare);
    return true;
}

// Function to find a specific node in the tree.
BSTValue bst_find(BST *tree, BSTKey key)
{
    if (!tree)
        return NULL;
    BSTNode *node = bst_find_node(tree->root, key, tree->compare);
    return node ? node->value : NULL;
}

// Function to remove a key-value pari from the tree.
bool bst_remove(BST *tree, BSTKey key)
{
    if (!tree)
        return false;
    tree->root = bst_remove_node(tree->root, key, tree->compare);
    return true;
}

// Traverse our tree inorder.
void bst_inorder_traversal(BST *tree, void (*visit)(BSTNode *node))
{
    if (!tree)
        return;
    inorder(tree->root);
}