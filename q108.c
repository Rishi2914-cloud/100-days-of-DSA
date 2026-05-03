int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int maxNodes = 2000;

    int** result = (int**)malloc(maxNodes * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxNodes * sizeof(int));

    struct TreeNode** queue = (struct TreeNode**)malloc(maxNodes * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int levelCount = 0;
    int leftToRight = 1;  // Direction flag

    while (front < rear) {
        int size = rear - front;

        result[levelCount] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[levelCount] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            // Place value based on direction
            int index = leftToRight ? i : (size - 1 - i);
            result[levelCount][index] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
        }

        leftToRight = !leftToRight;  // Flip direction each level
        levelCount++;
    }

    *returnSize = levelCount;
    free(queue);
    return result;
}