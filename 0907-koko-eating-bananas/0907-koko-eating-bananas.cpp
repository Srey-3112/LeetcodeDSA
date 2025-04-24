// First calaulate MAX element from given array. Then initialized low=1 and 
// High =max (array of 1 -> max) amd at end returning low 

//TC: o(n)* o(log (max) base 2)
//SC: o(1)

class Solution {

private:
    double hoursCal(vector<int> &arr, int mid){

        int n=arr.size();
        double totalHrs=0;
        for(int i=0;i<n;i++){
            totalHrs+= ceil((double)arr[i]/(double)mid);
        }
        return totalHrs;
    }
    int maxE(vector<int> &arr){
        int n=arr.size();
        int max=INT_MIN;
        for(int i=0; i<n; i++){
            if(arr[i]>max) max=arr[i];
        }
        return max;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=maxE(piles);
        while(low<=high){
            int mid=(low+high)/2;
            double totalHrs = hoursCal(piles,mid);
            if(totalHrs<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;   
    }
};