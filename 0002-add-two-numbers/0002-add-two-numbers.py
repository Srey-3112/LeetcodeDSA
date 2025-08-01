# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy=ListNode()
        temp=dummy
        carry=0
        while l1 or l2 or carry:
            sum=0

            if l1:
                sum+=l1.val
                l1=l1.next

            if l2:
                sum+=l2.val
                l2=l2.next

            
            sum+=carry
            carry=sum//10

            newNode=ListNode(sum%10)
            temp.next=newNode
            temp=temp.next

        return dummy.next