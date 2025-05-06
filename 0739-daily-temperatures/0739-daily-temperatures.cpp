#include <vector>
using namespace std;

//TC: O(2N) = O(n)


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int n = temperatures.size();
    //     stack<int> st;
    //     vector<int> result(n);

    //     for(int i=n-1;i>=0;i--){

    //         while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
    //             st.pop();
    //         }

    //         if(st.empty()){
    //             result[i]=0;
    //         }else{
    //             result[i]=st.top()-i;
    //         }

    //         st.push(i);
    //     }

    //     return result;
    // }

    // optimised without stack
    int n = temperatures.size();
    vector<int> result(n, 0);
    int hottest = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        if(temperatures[i]>=hottest){
            hottest=temperatures[i];
            continue;
        }

        int day=1;
        while(temperatures[i]>=temperatures[i+day]){
            day=day+ result[i+day];
        }

        result[i]=day;
    }
    return result;
    
     
    }
        
};