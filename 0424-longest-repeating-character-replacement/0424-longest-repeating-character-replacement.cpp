class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxLen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int hash[26]={0};
            int maxF=0;
            for(int j=i;j<n;j++){
                hash[s[j] - 'A']++;
                maxF=max(maxF,hash[s[j] - 'A']);
                int rep=(j-i+1)-maxF;
                if(rep<=k){
                    maxLen=max(maxLen, (j-i+1));
                }else{
                    break;
                }
            }
        }
        return maxLen;
        
    }
};