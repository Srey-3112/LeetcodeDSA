class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        ### brute force
        #TC O(n2)
        #SC O(1)

        # for i in range(len(nums)):
        #     for j in range(i+1,len(nums)):
        #         if nums[i]==nums[j]:
        #             return True

        
        # return False

        ###sorting
        ## TC O(nlogn)
        ## SC O(1) 

        # nums.sort()

        # for i in range(1,len(nums)):
        #     if nums[i]==nums[i-1]:
        #         return True

        # return False

        ### HashSet
        ## TC : O(n)
        ## SC: O(n)

        # seen=set()
        # for num in nums:
        #     if num in seen:
        #         return True
        #     seen.add(num)

        # return False

        ### HashSet Length
        ## TC : O(n)
        ## SC: O(n)

        return len(set(nums)) < len(nums)




        ## using hashset will be trade off between using sorting as in hashing
        ## you will sacrifice space and reduce time complexity