#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // Empty tree has no leaf nodes
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;  // Current node is a leaf
    }
    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}
