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
    int dfsHeight(TreeNode* node){

        if(node==nullptr) return 0;
        
        int lf=dfsHeight(node->left);
        if(lf==-1) return -1;
        int rt=dfsHeight(node->right);
        if(rt==-1) return -1;

        if(abs(lf-rt)>1) return -1;


        return 1+max(lf,rt);

    }
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};