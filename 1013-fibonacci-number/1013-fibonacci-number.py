# TC: O(n)
# SC: O(n) stack space + O(n) dp array
class Solution(object):
    def f(self,n,dp):
        if n<=1:
            return n

        if dp[n] !=-1:
            return dp[n]
        
        dp[n]=self.f(n-1,dp)+self.f(n-2,dp)
        return dp[n]    

    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp=[-1]*(n+1)
        return self.f(n,dp)

       

        