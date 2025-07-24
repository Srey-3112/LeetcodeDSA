class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        
        # def func(i):

        #     if i>=len(cost):
        #         return 0
            
        #     if dp[i]!=-1:
        #         return dp[i]
            
        #     dp[i]=cost[i]+min(func(i+1),func(i+2))

        #     return dp[i]

        # n = len(cost)
        # dp = [0] * (n + 1)
        
        # for i in range(2, n + 1):
        #     dp[i] = min(dp[i - 1] + cost[i - 1],
        #                 dp[i - 2] + cost[i - 2])
        
        # return dp[n]



        for i in range(len(cost) - 3, -1, -1):
            cost[i] += min(cost[i + 1], cost[i + 2])

        return min(cost[0], cost[1])

        