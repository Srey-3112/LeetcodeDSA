class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        ### brute force will be as simple as running 2 for loops
        ## TC : O(n2)
        ## SC: O(1)


        ### using hashMap in one pass
        ## TC: O(n)
        ## SC : O(n)

        prevMap={}

        for i,n in enumerate(nums):
            diff= target-n

            if diff in prevMap:
                return [prevMap[diff],i]

            prevMap[n]=i
        

