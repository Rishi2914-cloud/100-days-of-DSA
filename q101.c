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
        return newNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to search for a value in BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;  // Found or reached NULL
    }
    if (key < root->val) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Build BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 60;
    struct TreeNode* result = search(root, key);

    if (result != NULL) {
        printf("Key %d found in BST.\n", key);
    } else {
        printf("Key %d not found in BST.\n", key);
    }

    return 0;
}

