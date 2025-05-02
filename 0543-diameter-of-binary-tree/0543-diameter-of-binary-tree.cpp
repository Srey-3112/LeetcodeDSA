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
    int maxHeight(TreeNode* node, int &diameter){
        if(node==nullptr) return 0;
        int lf=maxHeight(node->left, diameter);
        int rt=maxHeight(node->right, diameter);

        diameter=max(diameter,lf+rt);

        return 1+max(lf,rt);

    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter=0;
        maxHeight(root,diameter);
        return diameter;
        
    }
};