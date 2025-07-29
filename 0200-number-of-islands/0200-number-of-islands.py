class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """


        n=len(grid)
        m=len(grid[0])

        vis=[[0 for _ in range(m)] for _ in range(n)]

        count = 0    
        for i in range(n):
            for j in range(m):

                if not vis[i][j] and grid[i][j]=='1':

                    count+=1
                    #self.bfs(i,j,vis,grid)
                    self.dfs(i,j,vis,grid)

        return count

    def dfs(self,i,j,vis,grid):

        n=len(grid)
        m=len(grid[0])
        if self.isValid(n,m,i,j) and not vis[i][j] and grid[i][j]=='1':
            vis[i][j]=1
            self.dfs(i+1,j,vis,grid)
            self.dfs(i-1,j,vis,grid)
            self.dfs(i,j+1,vis,grid)
            self.dfs(i,j-1,vis,grid)






    # def bfs(self,i,j,vis,grid):
    #     vis[i][j]=1
    #     q=deque()
    #     q.append((i,j))
    #     n=len(grid)
    #     m=len(grid[0])
    #     while q:
    #         row,col=q.popleft()

    #         for delRow,delCol in ((1,0),(-1,0),(0,1),(0,-1)):

    #             newRow=row+delRow
    #             newCol=col+delCol

    #             if self.isValid(n,m,newRow,newCol) and not vis[newRow][newCol] and grid[newRow][newCol]=='1':
    #                 vis[newRow][newCol]=1
    #                 q.append((newRow,newCol))

    def isValid(self,n,m,row,col):

        if row<0 or row>=n:
            return False

        if col<0 or col>=m:
            return False

        return True