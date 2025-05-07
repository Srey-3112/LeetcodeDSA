class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> min;
    int k;
    KthLargest(int k, vector<int>& nums) {
        
        this->k=k;
        for(int &num:nums){
            min.push(num);
            if(min.size()>k) min.pop();
        }
        
    }
    
    int add(int val) {
        min.push(val);
        if(min.size()>k) min.pop();
        return min.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */