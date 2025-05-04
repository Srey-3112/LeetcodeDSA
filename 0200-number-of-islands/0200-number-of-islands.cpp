class Solution {
private:
    void bfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid){
        
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if (abs(i) + abs(j) != 1) continue;
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                            
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                    }
                }   
            }

        }

         
    }

    void dfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid){

        int n=grid.size();
        int m=grid[0].size();

        if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]=='1'){
            vis[row][col]=1;
            dfs(row+1,col,vis,grid);
            dfs(row-1,col,vis,grid);
            dfs(row,col+1,vis,grid);
            dfs(row,col-1,vis,grid);
        }
        return;

    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    island++;
                    //bfs(row,col,vis,grid);
                    dfs(row,col,vis,grid);
                }
            }
        }
        return island;
        
    }
};