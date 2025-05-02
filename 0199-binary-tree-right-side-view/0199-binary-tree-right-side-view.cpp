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
private:
    void rView(TreeNode* node, vector<int> &ans, int level){

        if(node==nullptr) return;
        if(level == ans.size()) ans.push_back(node->val);
        rView(node->right,ans,level+1);
        rView(node->left,ans,level+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if(root==nullptr) return ans;
        rView(root,ans,0);
        return ans;


        
    }
};