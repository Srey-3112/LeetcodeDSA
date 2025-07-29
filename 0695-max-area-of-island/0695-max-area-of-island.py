class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        n=len(grid)
        m=len(grid[0])

        vis=[[0 for _ in range(m)] for _ in range(n)]

        maxCount=0

        for i in range(n):
            for j in range(m):

                if grid[i][j]==1 and not vis[i][j]:
                    count=self.bfs(i,j,vis,grid)
                    maxCount=max(maxCount,count)


        return maxCount

    def bfs(self,i,j,vis,grid):
        vis[i][j]=1
        n=len(grid)
        m=len(grid[0])
        q=deque()
        q.append((i,j))
        count=1
        while q:
            row,col=q.popleft()

            for i,j in ((1,0),(0,1),(-1,0),(0,-1)):
                nr=row+i
                nc=col+j

                if self.isValid(nr,nc,n,m) and grid[nr][nc]==1 and vis[nr][nc]==0:
                    count+=1
                    vis[nr][nc]=1
                    q.append((nr,nc))
        return count

    def isValid(self,nr,nc,n,m):

        if nr<0 or nr>=n:
            return False

        if nc<0 or nc>=m:
            return False

        return True
        