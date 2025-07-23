class Solution:
    def partition(self, s):
        #your code goes here
        ans=[]
        self.func(0,s,[],ans)
        return ans

    def palindrome(self,s,start, end):            
        while start <= end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True

    def func(self,ind,s,current,ans):

        if ind==len(s):
            ans.append(current[:])
            return

        for i in range(ind,len(s)):
            if self.palindrome(s,ind,i):
                subStr=s[ind:i+1]
                current.append(subStr)
                self.func(i+1,s,current,ans)
                current.pop()