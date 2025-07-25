class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        # res=[]
        # for i in range(n+1):
        #     count=0
        #     while i:
        #         n&=n-1
        #         count+=1
        #     res.append(count)

        # dp=[0]*(n+1)
        # offset=1
        # for i in range(1,n+1):
        #     if offset*2==i:
        #         offset=i
            
        #     dp[i]=1+dp[i-offset]
        # return dp

        dp=[0]*(n+1)
        for i in range(1,n+1):
            dp[i]=dp[i>>1]+(i&1)
        return dp
        