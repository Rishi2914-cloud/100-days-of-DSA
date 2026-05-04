int cameras;

int dfs(struct TreeNode* node) {
    if (!node) return 2;  // NULL = covered (base case)

    int left  = dfs(node->left);
    int right = dfs(node->right);

    // A child is uncovered → MUST place camera here
    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    // A child has camera → this node is covered
    if (left == 1 || right == 1)
        return 2;

    // Both children covered but no camera nearby
    // → ask parent to cover us
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0)  // root itself uncovered
        cameras++;
    return cameras;
}