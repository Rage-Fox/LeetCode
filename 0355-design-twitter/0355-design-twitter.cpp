class Twitter {
public:
    // https://neetcode.io/solutions/design-twitter
    int count;
    unordered_map<int,vector<pair<int,int>>> tweetMap;
    unordered_map<int,unordered_set<int>> followMap;
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count,tweetId});
        if(tweetMap[userId].size()>10){
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        // Decrease 'count' so newer tweets have smaller values
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followMap[userId].insert(userId); // user follows themselves to get their own tweets
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        for(auto f:followMap[userId]){
            if(!tweetMap.count(f)){
                continue;
            }
            int idx=tweetMap[f].size()-1; // last is the latest tweet for that user/following
            auto &p=tweetMap[f][idx];
            minHeap.push({p.first,p.second,f,idx-1}); // idx-1 is for previous to latest tweet (assumption that maybe it's second before latest post)
        }
        while(!minHeap.empty() && res.size()<10){
            auto t=minHeap.top();
            minHeap.pop();
            res.push_back(t[1]);
            int idx=t[3];
            // push previous to the current following as it might include in the top 10 list
            if(idx>=0){
                auto &p=tweetMap[t[2]][idx];
                minHeap.push({p.first,p.second,t[2],idx-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)){
            followMap[followerId].erase(followeeId);
        }
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