/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        // Recursive call on left and right child
        int leftGain = max(maxGain(node->left), 0); // if the sub-path is negative, we ignore it
        int rightGain = max(maxGain(node->right), 0);

        // Price to start a new path where `node` is the highest node
        int priceNewpath = node->val + leftGain + rightGain;

        // Update maxSum if it's better to start a new path
        maxSum = max(maxSum, priceNewpath);

        // For recursion return the maximum gain if continue the same path
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
