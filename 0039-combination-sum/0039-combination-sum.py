class Solution(object):

    def func(self,n,arr,ind,sum,current,result):

        if sum == 0:
            result.append(current[:])
            return

        if sum<0 or ind==n:
            return

        self.func(n,arr,ind+1,sum,current,result)

        current.append(arr[ind])

        self.func(n,arr,ind,sum-arr[ind],current,result)

        current.pop()

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        result=[]
        current=[]
        self.func(len(candidates),candidates,0,target,current,result)
        return result
        