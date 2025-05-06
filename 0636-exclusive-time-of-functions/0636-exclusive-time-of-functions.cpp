class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        stack<int> st;
        vector<int> result(n,0);
        int prevTime=0;

        for(auto i: logs){

            int time=0;
            int id=0;
            bool isStart=true;

            int pos1= i.find(':');
            int pos2=i.find(':',pos1+1);

            id= stoi(i.substr(0,pos1));
            time=stoi(i.substr(pos2+1));
            isStart= (i.substr(pos1+1,pos2-pos1-1)== "start");

            if(isStart){
                if(!st.empty()){
                    result[st.top()]+= time-prevTime;
                }
                st.push(id);
                prevTime=time;

            }else{
                result[st.top()]+= time-prevTime+1;
                st.pop();
                prevTime=time+1;
            }

        }

        return result;
        
    }
};