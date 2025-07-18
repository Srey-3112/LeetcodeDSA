class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        ### sorting

        # if len(s)!=len(t):
        #     return False

        # return sorted(s)==sorted(t)


        ### hashtable
        ## SC O(1) since at max 26 character
        ## TC O(n+m)


        # if len(s)!=len(t):
        #     return False

        # tableS,tableT={},{}

        # for i in range(len(s)):
        #     tableS[s[i]] = 1+tableS.get(s[i],0)
        #     tableT[t[i]] = 1+tableT.get(t[i],0)

        # return tableS==tableT

        ### hasthtable using array

        # arr= [0]*26
        # if len(s)!=len(t):
        #     return False

        # for i in range(len(s)):
        #     arr[ord(s[i]) - ord('a')]+=1
        #     arr[ord(t[i]) - ord('a')]-=1

        # for val in arr:
        #     if val!=0:
        #         return False

        # return True


        ### using set

        if len(s) != len(t) :
            return False
        ss = set(s)
        for i in ss :
            if  s.count(i) != t.count(i) :
                return False
        return True 



        