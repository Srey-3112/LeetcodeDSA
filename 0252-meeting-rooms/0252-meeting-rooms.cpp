class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {

        if(intervals.empty()) return true;
        sort(intervals.begin(),intervals.end(),comp);
        int lastEndTime=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastEndTime){
                lastEndTime=intervals[i][1];
            }else{
                return false;
            }
        }

        return true;

        
    }
};


