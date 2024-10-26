class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n,1);
        int prefix=1;
        int suffix=1;

        for(int i=1;i<n;i++){
            prefix= nums[i-1]*prefix;
            answer[i]=answer[i]*prefix;
        }
        for(int i=n-2;i>=0;i--){
            suffix=nums[i+1]*suffix;
            answer[i]=suffix*answer[i];
        }
        return answer;



        // vector<int> prefix(n,1);
        // vector<int> suffix(n,1);

        // for(int i=1; i<n;i++){
        //     prefix[i]= prefix[i-1]*nums[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=suffix[i+1]*nums[i+1];
        // }
        // for(int i=0;i<n;i++){
        //     answer[i]=prefix[i]*suffix[i];
        // }
        // return answer;



    //   for(int i=0;i<nums.size();i++){
    //     int temp=1;
    //     for(int j=0;j<nums.size();j++){
    //         if(i!=j){
    //             temp=temp*nums[j];  
    //         }
    //     }
    //     answer.push_back(temp);
    //   }
    //   return answer;
      
    }
};