class MedianFinder {
public:

    priority_queue<double,vector<double>,greater<double>> right;
    priority_queue<double> left; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<left.top()){
            left.push(num);
        }else{
            right.push(num);
        }

        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (left.top()+right.top())/2;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */