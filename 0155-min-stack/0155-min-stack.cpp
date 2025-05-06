class MinStack {
public:

    // stack<long long> st;
	// long long min=INT_MAX;
    // MinStack() { }
    
    // void push(int val) {
    //     if(st.empty()){
    //         min=val;
    //         st.push(val);
    //     }else{
    //         if(val>min){
    //             st.push(val);
    //         }else{
    //             st.push(2LL*val - min);
    //             min=val; 
    //         }
    //     }    
    // }
    
    // void pop() {
        
    //     if(st.empty()) return;
    //     int x=st.top();
    //     st.pop();
    //     if(x<min){
    //         min=2*min-x;
    //     } 
    // }
    
    // int top() { 
        
    //     if(st.empty()) return -1;
    //     int x=st.top();
    //     if(x>min) return x;
    //     return min;
    // }
    
    // int getMin() { return min; }




    stack< pair<int,int> > s;
	
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push({val,val});
        else
            s.push({val,min(s.top().second,val)});    
    }
    
    void pop() { s.pop(); }
    
    int top() { return s.top().first; }
    
    int getMin() { return s.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */