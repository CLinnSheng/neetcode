/*
Post, follow, unfollow and view 10 most recent tweets
*/


class Twitter {
private:
    std::unordered_map<int, std::unordered_set<int>> following;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    using tweet = std::pair<int, int>;
    int timeStamp;

    struct comparator
    {
        bool operator()(const tweet& A, const tweet& B)
        {
            return A.first < B.first;
        }
    };

public:
    Twitter() : timeStamp{0} {}     
    
    // Save it into a hash map with value is an array that also track the timestamp
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timeStamp++, tweetId);
    }
    
    // 10 most recent tweet in the user's news feed. The feed must be either posted by the
    // users who the user is following or by the user themself. Most recent to least recent
    // push all the tweets from the user and the user's following into a heap
    // so we can easily access it
    vector<int> getNewsFeed(int userId) {
        std::vector<int> recentTweets;

        // Push itself into following so that will prcoess its own tweets as well
        following[userId].insert(userId);
        std::priority_queue<tweet, std::vector<tweet>, comparator> maxHeap;

        for (const auto& user : following[userId])
        {
            for (const auto& tweetpost : tweets[user])
                maxHeap.emplace(tweetpost);
        }

        while (!maxHeap.empty())
        {
            recentTweets.emplace_back(maxHeap.top().second);
            maxHeap.pop();

            if (recentTweets.size() == 10)
                break;
        }

        return std::move(recentTweets);
    }
    
    // Can use a hashmap to store all the users the user is following
    // value use a hash set, because we can easily access the particular user while unfollow
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
