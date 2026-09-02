#include <climits>
#include <vector>
using std::vector;
/*
 * At each day we can either buy or sell
 * So we can try it recursively, we can either skip or buy if we havent own the stock, and then we can choose to sell or
 * skip if we own the stock
 * We cannot buy the next day we sell the stock so we need to take care of this case
 * Time Complexity: O(2^N) as each day we can either skip or include it
 *
 * Observation from recursive, we are doing the same works for some subproblem we already seen.
 * So we can just cache it and reuse it when we see the same subproblem
 * It will be a 2d array as we passing the index and whether we own the stock or not
 * So dp[i][j] will just simply be the maximum profit at current index i if we owning the stock (i==1), not owning the
 * stock (i==0) until end of the prices
 * */
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        bool ownStock = false;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recursive(prices, 0, 0, dp);
    }

    int recursive(const std::vector<int> &prices, int index, int ownStock, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
        {
            return 0;
        }

        if (dp[index][ownStock] != -1)
        {
            return dp[index][ownStock];
        }

        int profit{INT_MIN};

        if (ownStock)
        {
            // Sell today or skip
            return dp[index][ownStock] = std::max(prices[index] + recursive(prices, index + 2, 0, dp),
                                                  recursive(prices, index + 1, ownStock, dp));
        }

        // Buy today or skip
        return dp[index][ownStock] = std::max(-prices[index] + recursive(prices, index + 1, 1, dp),
                                              recursive(prices, index + 1, ownStock, dp));
    }
};
