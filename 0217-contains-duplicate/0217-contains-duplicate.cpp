class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int,int> mpp;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it: mpp){
        //     if(it.second >= 2){
        //         return true;
        //     }
        // }
        // return false;


        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;

        // unordered_set<int> seen;
        // for(auto num: nums){
        //     if(seen.count(num)) return true;
        //     seen.insert(num);
        // }
        // return false;
    }
};