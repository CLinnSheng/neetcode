#include <algorithm>
#include <vector>
using std::vector;

/*
 * Similar to coin change I, except this time we finding the number of way to make up that amount
 * Can use the same method, so this time instead of getting the min, we collecting all of it
 * And also since we need to find `all` combination then we can either choose the current coin or skip it
 * coin can be use unlimited time also and unique combination
 * Time Complexity: O(2^n)
 *
 * Observation from recursive, doing same subproblem multiple time
 * Cache the result and reuse it
 * dp[i][j] --> Number of combination to get amount with currAmount i and from index j
 * */
class Solution
{
  public:
    int change(int amount, vector<int> &coins)
    {
        // Pre sort it so we can prune early
        std::sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        return recursive(amount, coins, 0, dp);
    }

    int recursive(int amount, const vector<int> &coins, const int currIndex, vector<vector<int>> &dp)
    {
        if (amount == 0)
        {
            return 1;
        }

        if (currIndex == coins.size())
        {
            return 0;
        }

        if (dp[amount][currIndex] != -1)
        {
            return dp[amount][currIndex];
        }

        int cnt{};
        if (amount >= coins[currIndex])
        {
            // Include
            cnt = recursive(amount - coins[currIndex], coins, currIndex, dp);
            // Skip
            cnt += recursive(amount, coins, currIndex + 1, dp);
        }

        return dp[amount][currIndex] = cnt;
    }
};
