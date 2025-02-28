class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int len=0;
        int maxLen=0;
        int n= s.size();

        for(int i=0;i<n;i++){
            int hash[255]={0};
            for(int j=i;j<n;j++){
                if(hash[s[j]] == 1) break;

                len=j-i+1;
                maxLen=max(len,maxLen);
                hash[s[j]]++;
            }
        }

        return maxLen;



        
    }
};