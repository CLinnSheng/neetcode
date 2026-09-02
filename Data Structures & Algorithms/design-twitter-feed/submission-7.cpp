#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::vector;

/*
 * Viewing 10 most recent tweets
 * We need to keep track of the post posted by the user
 * Need to keep track who the user is following
 * */
class Twitter
{
    // Storing who the user is following
    std::unordered_map<int, std::unordered_set<int>> followeeMap;

    // Storing the user's own tweet
    std::unordered_map<int, vector<std::pair<int, int>>> tweetsMap;

    // For tracking the tweet post time
    int time{};

    struct Comparator
    {
        bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B)
        {
            return A.second < B.second;
        }
    };

  public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweetsMap[userId].push_back({tweetId, time++});
    }

    // O(nlgn)
    vector<int> getNewsFeed(int userId)
    {
        vector<int> tweets;
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Comparator> maxHeap;

        // Get from both the user and its following user's tweet
        // We can push all into the maxHeap then only pop the most recent 10 tweets

        // Add user itself into its all following user so we also include user own post
        followeeMap[userId].insert(userId);
        for (const auto followee : followeeMap[userId])
        {
            for (const auto tweet : tweetsMap[followee])
            {
                maxHeap.push({tweet.first, tweet.second});
            }
        }

        int n = 10;
        while (!maxHeap.empty() && n)
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            tweets.push_back(top.first);

            n--;
        }

        return tweets;
    }

    void follow(int followerId, int followeeId)
    {
        followeeMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followeeMap[followerId].erase(followeeId);
    }
};
