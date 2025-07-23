class Solution:
    def partition(self, s):
        #your code goes here
        ans=[]
        current=[]
        
        
        def palindrome(s,start, end):            
            while start <= end:
                if s[start] != s[end]:
                    return False
                start += 1
                end -= 1
            return True

        def func(ind):

            if ind==len(s):
                ans.append(current[:])
                return

            for i in range(ind,len(s)):
                if palindrome(s,ind,i):
                    subStr=s[ind:i+1]
                    current.append(subStr)
                    func(i+1)
                    current.pop()
        
        func(0)
        return ans