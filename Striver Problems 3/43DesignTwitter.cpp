#include<bits/stdc++.h>
using namespace std;

class Twitter {
    unordered_map<int,set<int>> followTable;
    unordered_map<int,vector<pair<int,int>>> newsFeed;
    long long time;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        newsFeed[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it=newsFeed[userId].begin();it!=newsFeed[userId].end();it++){
            pq.push(*it);
        }
        for(auto it1=followTable[userId].begin();it1!=followTable[userId].end();it1++){
            int f=*it1;
            for(auto it2=newsFeed[f].begin();it2!=newsFeed[f].end();it2++){
                pq.push(*it2);
            }
        }

        vector<int> res;
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
            if(res.size()==10) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followTable[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followTable[followerId].erase(followeeId);
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

 // This is another method to solve the same question with maintaing a single array for whole posts

 class Twitter {
private:
    vector<pair<int,int>>posts;
    unordered_map<int, unordered_map<int, int>>follows;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        int count = 0;
        for(int i = posts.size() - 1; i >= 0 && count < 10; i--)
            if(posts[i].first == userId || follows[userId][posts[i].first])
                feed.push_back(posts[i].second), count++;
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
    }
};