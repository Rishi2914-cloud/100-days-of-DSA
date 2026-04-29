/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // Empty tree has depth 0
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Height is 1 (for current node) + max of left/right subtree depths
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
