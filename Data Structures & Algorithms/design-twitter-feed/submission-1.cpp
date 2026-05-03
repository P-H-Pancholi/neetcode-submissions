class Twitter {
public:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,set<int>> followees;
    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
        for(auto p : tweets[userId]){
            pq.push(p);
            if(pq.size() > 10){
                pq.pop();
            }
        }

        for(int id : followees[userId]){
            for(auto p : tweets[id]){
                pq.push(p);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followees[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
