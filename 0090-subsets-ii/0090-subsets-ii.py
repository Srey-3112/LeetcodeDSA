class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result=[]
        current=[]
        nums.sort()
        self.func(nums,0,current,result)

        return result



    def func(self,nums,ind,current,result):

        if ind==len(nums):
            result.append(current[:])
            return

        current.append(nums[ind])
        self.func(nums,ind+1,current,result)
        current.pop()

        # for i in range(ind+1,len(nums)):
        #     if nums[i] != nums[ind]:
        #         self.func(nums,i,current,result)
        #         return
        idx=ind+1
        while idx<len(nums) and nums[idx] == nums[idx-1]: #skipping the duplicate values
            idx+=1

        self.func(nums,idx,current,result)