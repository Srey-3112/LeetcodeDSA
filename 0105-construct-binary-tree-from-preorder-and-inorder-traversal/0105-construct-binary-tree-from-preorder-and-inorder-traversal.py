# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """
        inMap={val:idx for idx,val in enumerate(inorder)}

        def helper(preStart,preEnd,inStart,inEnd):

            if preStart>preEnd or inStart>inEnd:
                return None

            rootVal=preorder[preStart]
            root=TreeNode(rootVal)

            inIndex=inMap[rootVal]
            numLeft=inIndex-inStart

            root.left=helper(preStart+1,preStart+numLeft,inStart,inIndex-1)
            root.right=helper(preStart+numLeft+1,preEnd,inIndex+1,inEnd)

            return root
    
        return helper(0,len(preorder)-1,0,len(inorder)-1)
        