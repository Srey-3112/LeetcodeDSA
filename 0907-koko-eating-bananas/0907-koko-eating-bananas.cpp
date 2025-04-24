// First calaulate MAX element from given array. Then initialized low=1 and 
// High =max (array of 1 -> max) amd at end returning low 

//TC: o(n)* o(log (max) base 2)
//SC: o(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Binary search with number of working hours.
        int right = *max_element(piles.begin(),piles.end());
        int left = 1,mid;
        int hours;
        while(left<right)
        {
            mid = (left+right)/2;
            hours = 0;
            // checking the selected value of "hour" for all the piles.
            for(int pile:piles)
            {
                hours+= pile/mid + (pile%mid != 0);
            }
            // Checking if the working hour is below the limit or not
            if(hours<=h)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return right;
    }
};

// private:
//     bool hoursCal(vector<int> &arr, int mid, int h){

//         int n=arr.size();
//         int totalHrs=0;
//         for(int i=0;i<n;i++){
//             totalHrs+= ceil((double)arr[i]/mid);
//             if(totalHrs>h) return false;
//         }
//         return true;
//     }
//     int maxE(vector<int> &arr){
//         int n=arr.size();
//         int max=INT_MIN;
//         for(int i=0; i<n; i++){
//             if(arr[i]>max) max=arr[i];
//         }
//         return max;
//     }
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {

//         int low=1;
//         int high=maxE(piles);
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(hoursCal(piles,mid,h)){
//                 high=mid-1;
//             }
//             else low=mid+1;
//         }
//         return low;   
//     }
