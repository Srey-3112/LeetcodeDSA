class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        unordered_map<char,int> charCount;
        int l=0;
        int maxLen=0;

        for(int r=0;r<s.size();r++){
            charCount[s[r]]++;

            while(charCount.size()>2){
                charCount[s[l]]--;
                if(charCount[s[l]]==0){
                    charCount.erase(s[l]);
                }
                l++;
            }

            maxLen=max(maxLen,r-l+1);
        }


        return maxLen;
    }
};