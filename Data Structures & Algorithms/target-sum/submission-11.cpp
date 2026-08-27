#include <numeric>
#include <vector>
using std::vector;

/*
 * Find the number of ways where we can build the expression such that the sum equal to target
 * So for each index we can either subtract or plus.
 * So this make things easier, because basically at every index, we have 2 choices either subtract or plus.
 * We can just do it naively with recursive
 * And we must use all num in the nums array
 * Time Complexity: O(2^m)
 *
 * Observation from recursive, we solving the same subproblem multiple time
 * Why dont we just cache it and reuse it in the future?
 * dp[i][j] --> number of ways to get to target with currSum i and at index j
 * Time Complexity: O(T * n)
 * */
class Solution
{
  public:
    int total{};
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // Need to handle for negative number
        // range - sum <= x <= sum
        // So the index must be 2 * sum + 1
        // And to offset the negative number just simplysum up with total
        total = std::accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(2 * total + 1, vector<int>(nums.size(), -1));
        return recursive(nums, target, 0, 0, dp);
    }

    int recursive(const vector<int> &nums, const int target, int currSum, const int currIndex, vector<vector<int>> &dp)
    {
        if (currIndex == nums.size())
        {
            if (currSum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (dp[currSum + total][currIndex] != -1)
        {
            return dp[currSum + total][currIndex];
        }
        int cnt{};

        // Subtract
        cnt = recursive(nums, target, currSum - nums[currIndex], currIndex + 1, dp);

        // Plus
        cnt += recursive(nums, target, currSum + nums[currIndex], currIndex + 1, dp);

        return dp[currSum + total][currIndex] = cnt;
    }
};
