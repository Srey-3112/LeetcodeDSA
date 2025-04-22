class Solution {
private:
    int firstOcc(vector<int> &arr, int n, int x){
        
        int low=0;
        int high=n-1;
        int ans=n;

        while(low<=high){

            int mid=(low+high)/2;
            if(arr[mid]>= x){
                ans=mid;
                high=mid-1;
                
                
            }
            else low=mid+1;
        }
        return ans;
    }
    int lastOcc(vector<int> &arr, int n, int x){
        
        int low=0;
        int high=n-1;
        int ans=n;

        while(low<=high){

            int mid=(low+high)/2;
            if(arr[mid]> x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        
        int n=nums.size();
        int first= firstOcc(nums,n,target);
        
        if(first == n || nums[first] !=target) return {-1,-1};
        
        int last=lastOcc(nums,n,target);

        return {first,last-1};

    }
};