#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current root from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find root in inorder
    int pos = search(inorder, start, end, curr);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, start, pos - 1, preIndex);
    root->right = buildTree(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

// Inorder traversal to verify
void inorderPrint(struct Node* root) {
    if (root == NULL)
        return;

    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

// Driver code
int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[]  = {4, 2, 5, 1, 3};

    int n = 5;
    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Inorder of constructed tree:\n");
    inorderPrint(root);

    return 0;
}