class Solution:
    def combinationSum2(self, nums, target):
        self.res = []
        self.count = defaultdict(int)
        cur = []
        A = []
        
        for num in nums:
            if self.count[num] == 0:
                A.append(num)
            self.count[num] += 1
        self.backtrack(A, target, cur, 0)
        return self.res

    def backtrack(self, nums, target, cur, i):
        if target == 0:
            self.res.append(cur[:])
            return
        if target < 0 or i >= len(nums):
            return
        
        if self.count[nums[i]] > 0:
            cur.append(nums[i])
            self.count[nums[i]] -= 1
            self.backtrack(nums, target - nums[i], cur, i)
            self.count[nums[i]] += 1
            cur.pop()

        self.backtrack(nums, target, cur, i + 1)


#class Solution(object):

    # def func(self,arr,ind,sum,current,result):

    #     if sum==0:
    #         result.append(current[:])
    #         return 

    #     if sum<0 or ind==len(arr):
    #         return


    #     current.append(arr[ind])
    #     self.func(arr,ind+1,sum-arr[ind],current,result)
    #     current.pop()

    #     for i in range(ind+1,len(arr)):
    #         if arr[i] != arr[ind]:
    #             self.func(arr,i,sum,current,result)
    #             break


    # def combinationSum2(self, candidates, target):
    #     """
    #     :type candidates: List[int]
    #     :type target: int
    #     :rtype: List[List[int]]
    #     """

    #     candidates.sort()

    #     result=[]
    #     current=[]

    #     self.func(candidates, 0, target, current, result)

    #     return result
    
       




        