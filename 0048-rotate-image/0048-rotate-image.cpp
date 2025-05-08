class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //[0][j]=[i][n-1]
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n,0));

        //brute force

        //TC:O(n*n)
        //SC: O(n*n);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         ans[j][n-1-i]=matrix[i][j];
        //     }
        // }

        // matrix=ans; 

        //optimal

        //TC: for every swapping (n-1)+(n-2)+....+1 = n*(n-1)/2 = O(n*n) and 
        //for reverse also O(n*n) total= O(2n*n)= overall O(n*n)
        //SC: O(1)

        //O(n*n)
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }   
        //O(n*n)
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        } 
    }
};