class Solution:
    def isValid(self, i, j, n, m):
        
        # Return false if cell is invalid
        if i < 0 or i >= n:
            return False
        if j < 0 or j >= m:
            return False
            
        # Return true if cell is valid
        return True
    def orangesRotting(self, grid):

        n=len(grid)
        m=len(grid[0])

        vis=[[0 for _ in range(m)] for _ in range(n)]
        time=0
        total=0
        count=0

        q=deque()

        for i in range(n):
            for j in range(m):
                if grid[i][j] != 0:
                    total += 1

                if grid[i][j] == 2:
                    q.append((i, j))

        while q:
            count+=len(q)
            for _ in range(len(q)):
                
                row,col=q.popleft()

                for i,j in ((1,0),(0,1),(-1,0),(0,-1)):

                    nr=row+i
                    nc=col+j

                    if (self.isValid(nr, nc, n, m) 
                        and grid[nr][nc] == 1):

                        grid[nr][nc]=2
                        q.append((nr,nc))


            if q:
                time+=1

        if count==total:
            return time

        return -1
        