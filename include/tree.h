#ifndef TREE_H
#define TREE_H

/*
===============================================================================
TREE — CLASSIFICATION ENGINE
===============================================================================
*/

typedef enum {
    NORMAL,
    SUSPICIOUS,
    ATTACK
} Classification;

typedef struct TreeNode {
    Classification type;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* create_node(Classification type);
Classification classify_user(int failed_attempts);
void tree_traverse(TreeNode *root);
void tree_free(TreeNode *root);

#endif
