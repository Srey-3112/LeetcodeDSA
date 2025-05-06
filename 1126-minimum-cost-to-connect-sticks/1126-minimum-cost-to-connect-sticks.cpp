class Solution {
public:
    int connectSticks(vector<int>& sticks) {

        priority_queue<int,vector<int>,greater<int>> minHeap(sticks.begin(),sticks.end());
        int cost=0;

        while(minHeap.size()>1){
            int first=minHeap.top();
            minHeap.pop();
            int second=minHeap.top();
            minHeap.pop();
            int sum=first+second;
            cost+=sum;
            minHeap.push(sum);
        }
        return cost;
        
    }
};