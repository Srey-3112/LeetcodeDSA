class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        dp=[-1]*len(cost)
        def func(i):

            if i>=len(cost):
                return 0
            
            if dp[i]!=-1:
                return dp[i]
            
            dp[i]=cost[i]+min(func(i+1),func(i+2))

            return dp[i]



        return min(func(0),func(1))

        