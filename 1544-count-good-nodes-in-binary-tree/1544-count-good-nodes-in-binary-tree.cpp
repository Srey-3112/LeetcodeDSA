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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root, root->val});
        int ans=0;

        while(!q.empty()){
            auto [node,maxSoFar]=q.front();
            q.pop();

            if (node->val>=maxSoFar) ans++;

            int newMax=max(maxSoFar,node->val);
            if (node->left) q.push({node->left,newMax});
            if (node->right) q.push({node->right,newMax});
        }
        return ans;
    }
};