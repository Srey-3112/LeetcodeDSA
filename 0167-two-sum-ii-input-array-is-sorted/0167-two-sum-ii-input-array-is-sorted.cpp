class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        vector<int> ans;

        // for(int i=0;i<n;i++){

        //     int j=i+1;
        //     while(j<n){
        //         if(nums[i]+nums[j] == target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);

        //         }
        //         j++;
        //     }
        // }

        // return ans;

        int left=0;
        int high= n-1;

        while(left<=high){

            if(nums[left]+nums[high]> target){
                high--;
            }else if (nums[left]+nums[high]< target){
                left++;
            }else{
                return { left + 1, high + 1 };
            }
        }
        return {};


        
    }
};