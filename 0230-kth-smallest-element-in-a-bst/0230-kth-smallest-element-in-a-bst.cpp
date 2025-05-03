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
    int kthSmallest(TreeNode* root, int k) { 

        int count=0;
        int ans=-1;
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                if(++count==k) ans=curr->val;
                curr=curr->right;
            }else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=nullptr;
                    if(++count==k) ans=curr->val;
                    curr=curr->right;
                }
            }

        }
        return ans;
        
    }
};