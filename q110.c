int* rightSideView(struct TreeNode* root, int* returnSize) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int maxNodes = 2000;

    int* result = (int*)malloc(maxNodes * sizeof(int));
    struct TreeNode** queue = (struct TreeNode**)malloc(maxNodes * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int levelCount = 0;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            // Only capture the LAST node of each level
            if (i == size - 1)
                result[levelCount] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
        }

        levelCount++;
    }

    *returnSize = levelCount;
    free(queue);
    return result;
}