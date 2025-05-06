class Twitter {
    unordered_map<int, vector<pair<int,int>>> tweet;
    unordered_map<int, unordered_set<int>> follows;
    int time=0;

public:
    Twitter() {
        time=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].emplace_back(time++,tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first; // min-heap based on time
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_set<int> users=follows[userId];
        vector<int> result;
        users.insert(userId);
        for(int uid:users){
            for(auto& t: tweet[uid]){
                pq.push(t);
            }
        }
        int count=0;
        while(!pq.empty() && count<10){
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        //reverse(result.begin(), result.end());
        return result;
        
    }
     
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            follows[followerId].insert(followeeId);
        }

        
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */