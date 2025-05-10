class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //optimised

        unordered_set<int> numSet(nums.begin(),nums.end());
        int maxLen=0;

        for(auto num: numSet){

            if(numSet.find(num-1)==numSet.end()){
                int currentNum=num;
                int count=1;

                while(numSet.find(currentNum+1) !=numSet.end()){
                    currentNum+=1;
                    count++;
                }
                maxLen=max(count,maxLen);

            }
        }

        return maxLen;

        // brute force

        // int n=nums.size();

        // if(nums.empty()) return 0;

        // sort(nums.begin(),nums.end());

        // int count=1;
        // int maxCount=1;
        // for(int i=1;i<n;i++){
        //     if(nums[i] == nums[i-1]) continue;

        //     if(nums[i]-nums[i-1] == 1){
        //         count++;
        //     }else{
        //         maxCount=max(maxCount,count);
        //         count=1;
        //     }
            
        // }
        // maxCount=max(maxCount,count);
        // return maxCount;
        
    }
};