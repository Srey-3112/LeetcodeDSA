class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        # res=0
        # while n:
        #     n&=n-1
        #     res+=1
        # return res

        # res=0
        # for i in range(32):
        #     if ((n>>i)&1):
        #         res+=1
        # return res

        res=0

        while n:
            if n&1:
                res+=1
            n>>=1
        return res


        
                

        