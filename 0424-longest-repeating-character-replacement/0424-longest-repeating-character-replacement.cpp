class Solution {
public:
    int characterReplacement(string s, int k) {

        

        // int maxLen=0;
        // for(int i=0;i<s.size();i++){
        //     int hash[26]={0};
        //     int maxF=0;
        //     for(int j=i;j<s.size();j++){
        //         hash[s[j]-'A']++;
        //         maxF=max(maxF, hash[s[j]-'A']);
        //         int changes= (j-i+1)-maxF;
        //         if(changes<=k){
        //             maxLen=max(maxLen,(j-i+1));
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxLen;

        int maxLen=0;
        int l=0, r=0;
        int maxF=0;
        map<char,int> mpp;

        while(r<s.size()){
            mpp[s[r]]++;
            maxF=max(maxF,mpp[s[r]]);
            int changes= (r-l+1)-maxF;
            if(changes <= k){
                maxLen=max(maxLen, r-l+1);
            }
            else{
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
};