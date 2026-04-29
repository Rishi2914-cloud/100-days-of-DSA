/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloc'ed, assume caller calls free().
 */
void preorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    // Visit root
    result[(*returnSize)++] = root->val;

    // Traverse left
    preorderHelper(root->left, result, returnSize);

    // Traverse right
    preorderHelper(root->right, result, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate space for result (max 100 nodes for safety, adjust as needed)
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    preorderHelper(root, result, returnSize);

    return result;
}
