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

// Recursive function to find maximum depth
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // Empty tree has depth 0
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
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

    printf("Maximum Depth of Tree: %d\n", maxDepth(root));

    return 0;
}
