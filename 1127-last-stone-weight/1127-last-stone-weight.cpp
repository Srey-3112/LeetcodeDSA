class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq(stones.begin(),stones.end());

        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
                int diff= abs(y-x);
                pq.push(diff);
            }
        }

        if(pq.size()==1) return pq.top();

        return 0;
        
    }
};