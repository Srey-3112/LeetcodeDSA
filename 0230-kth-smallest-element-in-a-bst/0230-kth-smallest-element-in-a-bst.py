# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        self.k=k
        self.result=None
        self.inorder(root)
        return self.result

    def inorder(self,node):
        if node is not None:
            self.inorder(node.left)
            self.k-=1
            if self.k==0:
                self.result=node.val
                return
            self.inorder(node.right)



        