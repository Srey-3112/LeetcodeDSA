class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> newPair= {value,timestamp};
        store[key].push_back(newPair);
    }
    
    string get(string key, int timestamp) {

        vector<pair<string, int>> &val = store[key];
        int low=0;
        int high= val.size() -1;
        string res;

        while(low<=high){
            int mid=(low+high)/2;

            if(val[mid].second == timestamp) {return val[mid].first;}

            if(timestamp>val[mid].second){
                low=mid+1;
                res= val[mid].first;
            }else{
                high=mid-1;
            }
        }
        return res;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */