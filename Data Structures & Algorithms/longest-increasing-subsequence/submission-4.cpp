#include <vector>
using std::vector;

/*
 * Goal: Finding the longest increasing subsequence
 * Subsequence: Sequence derive from the given sequence by deleting some or no element without changing the relative
 * orders
 *
 * Intuition: Since we cannot change the order, then we cannot sort it
 * Therefore at every index we can either choose it or skip it
 * Naively, we can do it recursively
 * Time Complexity: O(2^n)
 *
 * If we observe from the recursive, we can see some subproblem is computed multiple times
 * We can actually cache the answer, so we dont have to recompute based on the lastIndex
 * So dp[i][j] = the longest increasing substring starting frmo i where last index is j
 * */

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        std::vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return recursive(nums, 0, -1, dp);
    }

    int recursive(const vector<int> &nums, int index, int lastIndex, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }

        if (lastIndex != -1 && nums[index] > nums[lastIndex] && dp[index][lastIndex] != -1)
        {
            return dp[index][lastIndex];
        }

        int len{};

        if (lastIndex == -1 || nums[index] > nums[lastIndex])
        {
            // Skip and choosing the current index
            len = std::max(1 + recursive(nums, index + 1, index, dp), recursive(nums, index + 1, lastIndex, dp));
        }
        else
        {
            len = std::max(len, recursive(nums, index + 1, lastIndex, dp));
        }

        if (lastIndex == -1)
        {
            dp[index][0] = len;
        }
        else
        {
            dp[index][lastIndex] = len;
        }
        return len;
    }
};
