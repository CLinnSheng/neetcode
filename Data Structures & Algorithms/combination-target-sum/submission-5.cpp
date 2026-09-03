#include <vector>
using std::vector;
/*
 * Return a list of all unique combinations of nums where the chosen numbers sum to target.
 * Since it mention all unique combinations then we have to try all possible --> Backtracking
 * And we can use any number unlimited number of times
 * */
class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(nums, target, subset, ans, 0, 0);

        return ans;
    }

    void dfs(const vector<int> &nums, int target, vector<int> &subset, vector<vector<int>> &ans, int index, int currSum)
    {
        if (currSum == target)
        {
            ans.push_back(subset);
            return;
        }

        if (currSum > target)
        {
            return;
        }

        for (int i{index}; i < nums.size(); i++)
        {
            // Push into the subset
            subset.push_back(nums[i]);
            dfs(nums, target, subset, ans, i, currSum + nums[i]);

            // Backtrack
            subset.pop_back();
        }
    }
};
