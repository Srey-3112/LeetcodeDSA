class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """


        result=defaultdict(list)

        for str in strs:
            count=[0]*26

            for c in str:
                count[ord(c)-ord('a')]+=1
            
            result[tuple(count)].append(str)

        return list(result.values())

        