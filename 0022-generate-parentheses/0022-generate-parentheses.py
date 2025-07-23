class Solution:
    def generate(self,n:int,current:str,open_count:int,close_count:int,result:list):

        if open_count==close_count==n:
            result.append(current)
            return

        if open_count<n:
            self.generate(n,current+'(',open_count+1,close_count,result)

        if close_count<open_count:
            self.generate(n,current+')',open_count,close_count+1,result)


        

    def generateParenthesis(self, n: int) -> List[str]:
        result=[]
        self.generate(n,"",0,0,result)
        return result
        