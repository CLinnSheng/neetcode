/*
Given an array of nums where nums[i] has a certain amount of money.
We need to return the maximum amount of money we can get from the array

Constraint: We cannot visit adjacent Houses were broken on the same night
eg: 1 2 3 4
if we first broke index 1 then we cannot broke into index 2, we can only choose
either 3 or 4 for the next 1

Intuition:
This is actually a tree decision problem, at every index we can choose to rob or not. If we choose to rob then we will
choose again at i + 2 or else we can choose not to and try again at i + 1
Recursion --> Memoziation (topDown) --> DP (bottomUp)

Time Complexity: O(n) because we just go through the array
Space Complexity: O(n)
*/
#include <algorithm>
#include <vector>
class Solution
{
  private:
    std::vector<int> dp;
    int helper(const int &index, std::vector<int> &nums)
    {
        // base case
        if (index >= nums.size())
            return 0;

        // memoziation
        if (dp[index] != -1)
            return dp[index];

        return dp[index] = std::max(helper(index + 1, nums), nums[index] + helper(index + 2, nums));
    }

  public:
    int rob(std::vector<int> &nums)
    {
        dp = std::vector<int>(nums.size(), -1);
        return helper(0, nums);
    }
};
