class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mpp;

        for(auto str: strs){
            string hashStr="";
            int freq[26]={0};
            for(char s : str) freq[s-'a']++;
            for(int i=0;i<26;i++){
                hashStr.push_back(freq[i]);
                hashStr.push_back('#');
            }
            mpp[hashStr].push_back(str); 
        }

        vector<vector<string>> anagram;
        for(auto it:mpp){
            anagram.push_back(it.second);
        }
        return anagram;
    }
};