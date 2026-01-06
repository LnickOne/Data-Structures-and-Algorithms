/*
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 10 条推文。
实现 Twitter 类：
Twitter() 初始化简易版推特对象
void postTweet(int userId, int tweetId) 根据给定的 tweetId 和 userId 创建一条新推文。
每次调用此函数都会使用一个不同的 tweetId 。
List<Integer> getNewsFeed(int userId) 检索当前用户新闻推送中最近  10 条推文的 ID 。
新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 按照时间顺序由最近到最远排序 。
void follow(int followerId, int followeeId) ID 为 followerId 的用户开始关注 ID 为 followeeId 的用户。
void unfollow(int followerId, int followeeId) ID 为 followerId 的用户不再关注 ID 为 followeeId 的用户。
示例：

输入
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
输出
[null, null, [5], null, null, [6, 5], null, [5]]

解释
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
twitter.follow(1, 2);    // 用户 1 关注了用户 2
twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2
*/
#include "ListNode.h"
#include <unordered_set>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
class Twitter
{
    class Tweet
    {
    public:
        int id;
        int time;
        Tweet(int id, int time)
        {
            this->id = id;
            this->time = time;
        }
    };
    class User
    {
    public:
        int id;
        unordered_set<int> followed;
        vector<Tweet> tweets;
        User() : id(0)
        {
            followed.clear();
            tweets.clear();
        }
        User(int id)
        {
            this->id = id;
            followed.clear();
            tweets.clear();
            // 用户自动关注自己
            followed.insert(id);
        }
    };
    class TweetCompare
    {
    public:
        bool operator()(const Tweet &a, const Tweet &b)
        {
            return a.time < b.time;
        }
    };

public:
    int time;
    unordered_map<int, User> userMap;
    Twitter()
    {
        time = 0;
        userMap.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        if (!userMap.count(userId))
        {
            userMap[userId] = User(userId);
        }
        userMap[userId].tweets.push_back(Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        if (!userMap.count(userId))
            return res;
        User &user = userMap[userId];
        priority_queue<Tweet, vector<Tweet>, TweetCompare> pq;
        for (int followeeId : user.followed)
        {
            vector<Tweet> &tweets = userMap[followeeId].tweets;
            // 只取每个用户的最新推文
            for (Tweet &tweet : tweets)
            {
                pq.push(tweet);
            }
        }
        int count = 0;
        while (!pq.empty() && count < 10)
        {
            res.push_back(pq.top().id);
            pq.pop();
            count++;
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        if (!userMap.count(followerId))
        {
            userMap[followerId] = User(followerId);
        }
        if (!userMap.count(followeeId))
        {
            userMap[followeeId] = User(followeeId);
        }
        userMap[followerId].followed.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (!userMap.count(followerId) || !userMap.count(followeeId))
            return;
        userMap[followerId].followed.erase(followeeId);
    }
};
int main()
{
    Twitter twitter;
    twitter.postTweet(1, 5);                      // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
    vector<int> result1 = twitter.getNewsFeed(1); // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
    cout << "Result 1: ";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }
    cout << endl;

    twitter.follow(1, 2);                         // 用户 1 关注了用户 2
    twitter.postTweet(2, 6);                      // 用户 2 发送了一个新推文 (推文 id = 6)
    vector<int> result2 = twitter.getNewsFeed(1); // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5]
    cout << "Result 2: ";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
    cout << endl;

    twitter.unfollow(1, 2);                       // 用户 1 取消关注了用户 2
    vector<int> result3 = twitter.getNewsFeed(1); // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
    cout << "Result 3: ";
    for (int i = 0; i < result3.size(); i++)
    {
        cout << result3[i] << " ";
    }
    cout << endl;
    return 0;
}