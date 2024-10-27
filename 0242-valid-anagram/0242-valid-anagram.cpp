class Solution {
public:
    bool isAnagram(string s, string t) {

         int freq[26]={0};
         int n=s.size();

         if(s.size() != t.size()) return false;

         for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
         }
         for(auto it : freq){
            if(it!=0) return false;
         }
         return true;


        // map<char,int> mpp;
        // if(s.size() != t.size()){
        //     return false;
        // }

        // for(int i=0;i<s.size();i++){
        //     mpp[s[i]]++;
        //     mpp[t[i]]--;
        // }
        // for(auto it : mpp){
        //     if(it.second !=0){
        //         return false;
        //     }
        // }
        // return true;

        
    }
};