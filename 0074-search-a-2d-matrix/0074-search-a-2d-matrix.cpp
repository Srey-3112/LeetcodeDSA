// main point of this problem is to figure out how you can get 2d index after 
//calculating mid.
// else this problem is simple binary search

//TC: O(log(m*n))
//SC: O(1)


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high= (n*m)-1;

        while(low<=high){
            int mid=(low+high)/2;
            int i=mid/m;
            int j=mid%m;

            if(matrix[i][j]==target) return true;

            if(target>matrix[i][j]){
                low=mid+1;
            }else high=mid-1;
        }
        return false;
        
    }
};