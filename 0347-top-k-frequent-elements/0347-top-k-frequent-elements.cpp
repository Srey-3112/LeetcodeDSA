class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Bucket where index = frequency
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto& [num, count] : freq) {
        buckets[count].push_back(num);
    }

    vector<int> result;
    for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
        for (int num : buckets[i]) {
            result.push_back(num); 
        }
    }

    return result;

        // unordered_map<int,int> mpp;

        // for(auto it:nums){
        //     mpp[it]++;
        // }

        // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        // for(auto it: mpp){
        //     minHeap.push({it.second,it.first});

        //     if(minHeap.size()>k){
        //         minHeap.pop();
        //     }
        // }

        // vector<int> result;
        // while(!minHeap.empty()){
        //     result.push_back(minHeap.top().second);
        //     minHeap.pop();
        // }
        // return result;
    }
};