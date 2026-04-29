#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
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

// Function to insert a value into BST
struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return newNode(key);  // Empty spot found, create new node
    }

    if (key < root->val) {
        root->left = insert(root->left, key);   // Insert in left subtree
    } else if (key > root->val) {
        root->right = insert(root->right, key); // Insert in right subtree
    }
    // If key == root->val, do nothing (BST usually doesn’t allow duplicates)

    return root;
}

// Inorder traversal to verify BST structure
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal of BST: ");
    inorder(root);

    return 0;
}
