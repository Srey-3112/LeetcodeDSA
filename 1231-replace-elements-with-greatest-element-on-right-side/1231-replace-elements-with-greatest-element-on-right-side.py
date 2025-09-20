class Solution(object):
    def replaceElements(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        n=len(arr)
        ans=[]
        maxE=arr[n-1]
        ans.append(-1)

        for i in range(n-2,-1,-1):
            ans.append(maxE)
            if arr[i]>maxE:
                maxE=arr[i]


        ans.reverse()
        return ans
