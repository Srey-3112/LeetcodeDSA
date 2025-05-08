class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // TC: O(m*n)
        // SC: O(n)+O(m)

        //int n=matrix.size();
        //int m=matrix[0].size();

        // vector<int> row(n,0);
        // vector<int> col(m,0);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=1;
        //             col[j]=1;
        //         } 
        //     }
        // }

        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(row[i]==1 || col[j ]==1){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();
        for (int i = 0; i < R; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }
            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }
        
    }
};