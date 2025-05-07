class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);
        for(char &ch:tasks){
            freq[ch-'A']++;
        }

        priority_queue<int> pq;
        int time=0;
        
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

        
        while(!pq.empty()){

            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }

            for(int &it:temp){
                if(it>0){
                    pq.push(it);
                }
            }

            if(pq.empty()){
                time+= temp.size();
            }else{
                time+= n+1;
            }
        }

        return time;
        
    }
};