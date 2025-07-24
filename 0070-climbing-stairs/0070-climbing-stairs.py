class Solution(object):

    # def func(self,n,dp):

    #     if n<=1:
    #         return 1

    #     if dp[n]!=-1:
    #         return dp[n]

    #     dp[n]=self.func(n-1,dp)+self.func(n-2,dp)

    #     return dp[n]
    
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        prev=prev2=1
        if n<=1:
            return prev
        
        for i in range(2,n+1):
            curr_i=prev+prev2
            prev2=prev
            prev=curr_i

        return prev 
        