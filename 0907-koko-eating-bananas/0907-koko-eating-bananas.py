import math
class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """

        m=self.findMax(piles)
        low,high=1,m
        while low<=high:

            mid=(low+high)//2

            totalHrs=self.calHours(piles,mid)

            if totalHrs<=h:
                high=mid-1
            else:
                low=mid+1
        
        return low

    def calHours(self,nums,idx):
        totalhrs=0
        for i in range(len(nums)):
            totalhrs+=(nums[i] + idx - 1) // idx
        return totalhrs

    def findMax(self,nums):
        m=float('-inf')
        for i in range(len(nums)):
            m=max(m,nums[i])
        return m
        