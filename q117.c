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

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Last element in postorder is root
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(curr);

    // If only one node
    if (start == end)
        return root;

    int pos = search(inorder, start, end, curr);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

// Inorder traversal (to verify)
void inorderPrint(struct Node* root) {
    if (root == NULL)
        return;

    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

int main() {
    int inorder[]   = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = 5;

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder of constructed tree:\n");
    inorderPrint(root);

    return 0;
}