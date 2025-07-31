# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """

        if root is None:
            return None

        curr=root.val

        if p.val<curr and q.val<curr:
            return self.lowestCommonAncestor(root.left,p,q)
        if p.val>curr and q.val>curr:
            return self.lowestCommonAncestor(root.right,p,q)

        return root
        