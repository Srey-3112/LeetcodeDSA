class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        dp=[0]*(n+2)

        for i in range(n-1,-1,-1):
            pick=nums[i]+dp[i+2]
            notPick= dp[i+1]

            dp[i]=max(pick,notPick)

        return dp[0]
        # def func(ind):

        #     if ind>=len(nums):
        #         return 0

        #     if dp[ind]!=-1:
        #         return dp[ind]

        #     pick= nums[ind]+func(ind+2)
        #     nPick=0+func(ind+1)

        #     dp[ind]=max(pick,nPick)
        #     return dp[ind]

        
        

        