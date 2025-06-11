// gready approaches failes here please look into it.
// in this approach we will be using constant window size and simultaniously
// calculating lsum and rsum and storing maximum sum everytime.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int lsum=0;
        int rsum=0;
        int n=cardPoints.size();

        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }

        int maxSum=lsum;
        int rPointer=n-1;
        for(int i=k-1;i>=0;i--){

            lsum-=cardPoints[i];
            rsum+=cardPoints[rPointer];
            rPointer--;
            maxSum= max(maxSum,lsum+rsum);
        }

        return maxSum;
        
    }
};