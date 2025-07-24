class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp=[-1]*len(nums)
        def func(ind):


            if ind>=len(nums):
                return 0

            if dp[ind]!=-1:
                return dp[ind]

            pick= nums[ind]+func(ind+2)
            nPick=0+func(ind+1)

            dp[ind]=max(pick,nPick)
            return dp[ind]

        
        return func(0)

        