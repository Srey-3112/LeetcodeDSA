class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ans=[]
        temp=1
        ans.append(temp)
        r=rowIndex+1
        for i in range(1,r):

            temp=temp*(r-i)
            temp=temp//i
            ans.append(temp)
        
        return ans