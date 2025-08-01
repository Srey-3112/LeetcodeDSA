//In this problem first we first found which part is sorted. Further we found min
//from sorted and eliminated that sorted part and moved low or high accordingly
// to unsorted array. 

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n=nums.size();
        int low=0;
        int high= n-1;
        int ans= INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){
                ans=min(ans,nums[low]);
                break;
            };
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
        
    }
};