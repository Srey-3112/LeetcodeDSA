class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // Sort by end time
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);
        int count=1;
        int lastEndTime=intervals[0][1];

        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=lastEndTime){
                count++;
                lastEndTime=intervals[i][1];
            }

        }
        return intervals.size()-count;

        
    }
};