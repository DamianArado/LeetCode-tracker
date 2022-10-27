class Twitter {
private:
    vector<pair<int, int>> posts;
    unordered_map<int, unordered_map<int, int>> follows;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.emplace_back(userId, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for(int i = posts.size() - 1, count = 0; i >= 0 and count < 10; --i)
            if(posts[i].first == userId or follows[userId][posts[i].first])
                feed.emplace_back(posts[i].second), ++count;
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
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