# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """

        res=[]
        self.recursion(root,0,res)
        return res

    def recursion(self,node,level,res):
        
        if node is None:
            return

        if level==len(res):
            res.append(node.val)

        self.recursion(node.right,level+1,res)
        self.recursion(node.left,level+1,res)
