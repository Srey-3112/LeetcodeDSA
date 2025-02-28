class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // int len=0;
        // int maxLen=0;
        // int n= s.size();

        // for(int i=0;i<n;i++){
        //     int hash[255]={0};
        //     for(int j=i;j<n;j++){
        //         if(hash[s[j]] == 1) break;

        //         len=j-i+1;
        //         maxLen=max(len,maxLen);
        //         hash[s[j]]++;
        //     }
        // }

        // int maxLen=0;
        // int n=s.size();

        // int hash[255]={-1};
        // int left=0;
        // int right=0;

        // if(!s.empty()){
        //     while(right<n){

        //         if(hash[s[right]] > -1){
        //             if(hash[s[right]] >= left){
        //                 left= hash[s[right]]+1;
        //             } 
        //         }
                
        //         hash[s[right]]=right;
        //         int len= right-left+1;
        //         maxLen=max(len,maxLen);
        //         right++;
        //     }
        // }


        unordered_set<char> charSet;
        int l=0;
        int maxLen=0;

        for(int r=0;r<s.size();r++){

            while(charSet.find(s[r]) != charSet.end()){
                charSet.erase(s[l]);
                l++;
            }

            maxLen=max(maxLen,r-l+1);
            charSet.insert(s[r]);
        }


        return maxLen;



        
    }
};