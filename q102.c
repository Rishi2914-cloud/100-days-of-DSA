/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;  // Not found
    }

    if (root->val == val) {
        return root;  // Found the node
    }

    if (val < root->val) {
        return searchBST(root->left, val);  // Search in left subtree
    } else {
        return searchBST(root->right, val); // Search in right subtree
    }
}
