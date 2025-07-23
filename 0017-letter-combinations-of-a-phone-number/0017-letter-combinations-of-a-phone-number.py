class Solution:
    def __init__(self):
        self.map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    def letterCombinations(self, digits):
        #your code goes here
        ans=[]
        if not digits:
            return ans 

        self.func(digits,ans,0,"")
        return ans

    def func(self,digits,ans,ind,current):

        if ind==len(digits):
            ans.append(current)
            return

        s= self.map[int(digits[ind])]

        for char in s:
            self.func(digits,ans,ind+1,current+char)
        