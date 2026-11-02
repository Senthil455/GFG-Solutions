#include <stdlib.h>

int computeTilt(struct TreeNode* root, int* totalTilt) {
    if (root == NULL) return 0;

    int leftSum = computeTilt(root->left, totalTilt);
    int rightSum = computeTilt(root->right, totalTilt);

    int nodeTilt = abs(leftSum - rightSum);
    *totalTilt += nodeTilt;

    return root->val + leftSum + rightSum;
}

int findTilt(struct TreeNode* root) {
    int totalTilt = 0;
    computeTilt(root, &totalTilt);
    return totalTilt;
}