#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
bool isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min-Heap property
bool isMinHeap(struct Node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child
    if (root->right == NULL) {
        return (root->data <= root->left->data);
    }

    // Both children exist
    if (root->data <= root->left->data &&
        root->data <= root->right->data) {
        return isMinHeap(root->left) && isMinHeap(root->right);
    }

    return false;
}

// Main check function
bool isHeap(struct Node* root) {
    int totalNodes = countNodes(root);
    return isComplete(root, 0, totalNodes) && isMinHeap(root);
}

// Driver code
int main() {
    /*
            10
           /  \
         15    20
        /  \
      30   40
    */

    struct Node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    if (isHeap(root))
        printf("Tree satisfies Min-Heap\n");
    else
        printf("Tree does NOT satisfy Min-Heap\n");

    return 0;
}