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
    int maxHeight(TreeNode* node){

        if(node==nullptr) return 0;
        int lf=maxHeight(node->left);
        int rt=maxHeight(node->right);

        return 1+max(lf,rt);

    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int leftMaxHeight= maxHeight(root->left);
        int rightMaxHeight= maxHeight(root->right);

        if(abs(rightMaxHeight-leftMaxHeight) >1){
                return false;
        } 

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(!left || !right) return false;
        return true; 

        
    }
};