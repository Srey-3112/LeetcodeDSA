class Solution:

    def func(self,n:int,nums:List[int],ind:int,current:List[int],result:List[List[int]]):

        if ind==n:
            result.append(current[:])
            return

        self.func(n,nums,ind+1,current,result)
        current.append(nums[ind])
        self.func(n,nums,ind+1,current,result)
        current.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:

        result=[]
        current=[]
        self.func(len(nums),nums,0,current,result)
        return result
        