#include <climits>
#include <cstdlib>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>
using std::vector;

class Solution
{
  public:
    int lastStoneWeightII(vector<int> &stones)
    {
        // Always samsh the two stones that is closest in term of weight
        // We can use a queue so we always smash the two heaviest stone
        // This is a greedy apporach, but this doesnt always works out
        // for instance [8,7,6,5,4]
        // Greedy Appraoch -> 2
        // Ideally -> 0
        // So for each time we are free to choose whatever stones we want to split
        // So in another is actually we try to find two parition such that their sum is as close as to the hlaf of the
        // total sum
        // So that thier diff is the smallest
        // Time Complexity: O(2^n) because at each index we are choosing do we want to be inlcude in the partition or
        // not We can further optimize it by using caching because if you observer from the recursive appraoch some
        // subproblem are sovled multiple times.
        // cache[i][j] --> The min diff at index i when currSum is J

        int ttlSum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = (ttlSum + 1) / 2;

        vector<vector<int>> cache(stones.size(), vector<int>(target + 1, INT_MAX));

        return dfs(stones, target, ttlSum, 0, 0, cache);
    }

    int dfs(const vector<int> &stones, const int targetSum, const int ttlSum, int index, int currSum,
            vector<vector<int>> &cache)
    {
        if (currSum >= targetSum || index == stones.size())
        {
            return std::abs(currSum - (ttlSum - currSum));
        }

        if (cache[index][currSum] != INT_MAX)
        {
            return cache[index][currSum];
        }

        return cache[index][currSum] =
                   std::min(dfs(stones, targetSum, ttlSum, index + 1, currSum, cache),
                            dfs(stones, targetSum, ttlSum, index + 1, currSum + stones[index], cache));
    }
};
