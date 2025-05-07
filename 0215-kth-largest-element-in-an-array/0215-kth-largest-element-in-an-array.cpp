class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //priority_queue<int,vector<int>,greater<int>> pq;

        // minheap 
        // TC O(nlogk)
        // for(auto it: nums){
        //     pq.push(it);
        //     if(pq.size()>k){
        //         pq.pop();
        //     }

        // }
        //max Heap
        //TC O(nlogn)
        // for(auto it:nums){
        //     pq.push(it);
        // }
        // for(int i=0;i<k-1;i++){
        //     pq.pop();
        // }
        //return pq.top();
        return quickSelect(nums,k);
    }

    int quickSelect(vector<int> &nums,int k){
        // Select pivot at random.
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for(int num:nums){
            if(num > pivot){
                left.push_back(num);
            }
            else if(num<pivot){
                right.push_back(num);
            }
            else{
                mid.push_back(num);
            }
        }

        if(k <= left.size()){
            return quickSelect(left,k);
        }

        if(left.size() + mid.size() < k){
            return quickSelect(right, k - left.size() - mid.size());
        }
        return pivot;
    }
    
};