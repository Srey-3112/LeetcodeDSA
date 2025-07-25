class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();
        int low= 0;
        int high= n-1;

        if(nums[low] == target) return low;
        if(nums[high] == target) return high;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if( nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
        
    }
};