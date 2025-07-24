class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp1=[]
        temp2=[]
        n=len(nums)
        if n==1:
            return nums[0]
        for i in range(0,len(nums)):
            if i!=0:
                temp1.append(nums[i])
            if i!=n-1:
                temp2.append(nums[i])

        
        def func(arr):
            n=len(arr)
            dp=[0]*(n+2)

            for i in range(n-1,-1,-1):

                pick=arr[i]+dp[i+2]
                notPick=dp[i+1]

                dp[i]=max(pick,notPick)

            
            return dp[0]
        
        return max(func(temp1),func(temp2))