class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2= nums2.size();
        stack<int> st;
        map<int,int> mpp;
        vector<int> result;

        
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()){
                mpp[nums2[i]]=-1;
            }else{
                mpp[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }

        for(int j : nums1){
            result.push_back(mpp[j]);
        }

        return result;

        
        
    }
};