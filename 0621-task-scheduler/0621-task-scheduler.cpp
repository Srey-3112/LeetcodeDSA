class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        //Brute force using PQ.

        // vector<int> freq(26,0);
        // for(char &ch:tasks){
        //     freq[ch-'A']++;
        // }

        // priority_queue<int> pq;
        // int time=0;
        
        // for(int i=0;i<26;i++){
        //     if(freq[i]>0){
        //         pq.push(freq[i]);
        //     }
        // }

        
        // while(!pq.empty()){

        //     vector<int> temp;
        //     for(int i=1;i<=n+1;i++){
        //         if(!pq.empty()){
        //             int f=pq.top();
        //             pq.pop();
        //             f--;
        //             temp.push_back(f);
        //         }
        //     }

        //     for(int &it:temp){
        //         if(it>0){
        //             pq.push(it);
        //         }
        //     }

        //     if(pq.empty()){
        //         time+= temp.size();
        //     }else{
        //         time+= n+1;
        //     }
        // }

        // return time;

        //optimised

        vector<int> freq(26,0);
        for(char &ch:tasks){
            freq[ch-'A']++;
        }

        sort(freq.begin(),freq.end());
        int maxFreq=freq[25]-1;
        int idleSlot= maxFreq*n;

        for(int i=24;i>=0 && freq[i]>0;i--){
            idleSlot-= min(maxFreq,freq[i]);
        }

        return idleSlot>0 ? idleSlot+tasks.size() : tasks.size();
        
    }
};