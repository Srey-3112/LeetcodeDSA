class Solution(object):

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
    
        def __init__(self):
            self.ans = []
        
        def func(self, ind, sum, nums, candidates):
            # If the sum is zero, add the current combination to the result
            if sum == 0:
                self.ans.append(nums[:])
                return
            
            # If the sum is negative or we have exhausted the candidates, return
            if sum < 0 or ind == len(candidates):
                return
            
            # Include the current candidate
            nums.append(candidates[ind])
            
            # Recursively call with updated sum and next index
            self.func(ind + 1, sum - candidates[ind], nums, candidates)
            
            # Backtrack by removing the last added candidate
            nums.pop()
            
            # Skip duplicates: if not picking the current candidate, 
            # ensure the next candidate is different
            for i in range(ind + 1, len(candidates)):
                if candidates[i] != candidates[ind]:
                    self.func(i, sum, nums, candidates)
                    break

        def combinationSum2(self, candidates, target):
            candidates.sort()  # Sort candidates to handle duplicates
            self.ans = []
            self.func(0, target, [], candidates)
            return self.ans




        