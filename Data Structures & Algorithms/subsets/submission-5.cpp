#include <vector>
using std::vector;
/*
 * Find all possible subsets of nums
 * Since it mention `possible` -> Is a backtracking problem
 * Just use dfs and backtracking
 Time Complexity: O(2^n * n)
 * */
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(nums, subset, 0, ans);

        return ans;
    }

    void dfs(const vector<int> &nums, vector<int> &subset, int index, vector<vector<int>> &ans)
    {
        ans.push_back(subset);

        if (index == nums.size())
        {
            return;
        }

        for (int i{index}; i < nums.size(); i++)
        {
            // Push into it
            subset.push_back(nums[i]);
            dfs(nums, subset, i + 1, ans);

            // Backtrack
            subset.pop_back();
        }
    }
};
