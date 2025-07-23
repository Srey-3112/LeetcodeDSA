class Solution(object):

    def func(self,arr,ind,sum,current,result):

        if sum==0:
            result.append(current[:])
            return 

        if sum<0 or ind==len(arr):
            return


        current.append(arr[ind])
        self.func(arr,ind+1,sum-arr[ind],current,result)
        current.pop()

        for i in range(ind+1,len(arr)):
            if arr[i] != arr[ind]:
                self.func(arr,i,sum,current,result)
                break


    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        candidates.sort()

        result=[]
        current=[]

        self.func(candidates, 0, target, current, result)

        return result
        