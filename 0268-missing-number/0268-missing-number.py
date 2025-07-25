class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        # xor=n

        # for i in range(n):
        #     xor=xor^i^nums[i]
        # return xor
        res=n
        for i in range(n):
            res=res+i-nums[i]
        return res
        