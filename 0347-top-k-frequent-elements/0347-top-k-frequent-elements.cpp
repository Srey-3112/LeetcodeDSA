class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto it: mpp){
            minHeap.push({it.second,it.first});

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> result;
        // for(int i=k-1; i>=0;i--){
        //     result[i]=minHeap.top().second;
        //     minHeap.pop();
        // }
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};