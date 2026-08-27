#include <numeric>
#include <vector>
using std::vector;

/*
 * Check whether can we parition the array into 2 subset
 *
 * Intuition:
 * We doenst have to care how the subset is formed, as long as we can find whether the 2 subset are equal or not.
 * So we actually only need to handle 1 side, and if it equal to half of total then consider correct
 * We can do it recursively where at each index we can choose to include it or not.
 * Time Complexity: O(2^n)
 *
 * Observe from recursive method
 * We can see actaully some of the subproblem have been computed multiple times
 * We can actually cache the result then reuse
 * dp[i][j] --> Can we form a partition from index i where currSum is J?
 * */
class Solution
{
  public:
    bool canPartition(vector<int> &nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        // Base Case
        if (sum % 2 == 1)
        {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>((sum + 1) / 2, -1));
        return recursive(nums, 0, 0, sum, dp);
    }

    bool recursive(const vector<int> &nums, int currIndex, int currSum, const int total, vector<vector<int>> &dp)
    {
        // Base Case
        if (currIndex == nums.size())
        {
            return false;
        }

        if (currSum == total / 2)
        {
            return true;
        }

        if (dp[currIndex][currSum] != -1)
        {
            return dp[currIndex][currSum];
        }

        // Skipping current index
        bool firstChoice = recursive(nums, currIndex + 1, currSum, total, dp);
        bool seconChoice = false;

        // Include current index if can
        if (currSum + nums[currIndex] <= total / 2)
        {
            seconChoice = recursive(nums, currIndex + 1, currSum + nums[currIndex], total, dp);
        }

        dp[currIndex][currSum] = (firstChoice || seconChoice) ? 1 : 0;

        return dp[currIndex][currSum];
    }
};
