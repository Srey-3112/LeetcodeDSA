class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // int freq[26] ={0};

        // for(int i=0;i<s1.size();i++){
        //     freq[s1[i]-'a']++;
        // }

        

        // for(int i=0;i<s2.size();i++){
        //     int windIdx= 0, idx=i;
        //     int windFreq[26]={0};

        //     while(windIdx<s1.size() && idx<s2.size()){
        //         windFreq[s2[idx]-'a']++;
        //         idx++;
        //         windIdx++;
        //     }

        //     if(isFreqSame(freq,windFreq)){
        //         return true;
        //     }
        // }

        // return false;

        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);

        for(int i=0;i<s1.size();i++){
            freqs1[s1[i]-'a']++;
        }

        int i=0,j=0;
        while(j<s2.size()){

            if((j-i+1)<=s1.size()){
                freqs2[s2[j]-'a']++;
                j++;
            }
            else{
                freqs2[s2[i]-'a']--;
                i++;
            }

            if(freqs1 ==freqs2) return true;
        }
        
        return false;
    }
};