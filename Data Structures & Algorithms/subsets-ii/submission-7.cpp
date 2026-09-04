#include <algorithm>
#include <string>
#include <vector>
using std::vector, std::string;
/*
 * Finding all possible subsets
 * Keyword "all possible"
 * DFS & Backtracking
 * But we need to handle duplicate subsets And in any order so order doesnt matter.
 * TO easily prevent creating the duplicate subsets while iterating is pre sort the array then we can check it on the
 * fly
 * */

class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        dfs(ans, subset, nums, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &subset, const vector<int> &nums, int index)
    {
        ans.push_back(subset);

        if (index == nums.size())
        {
            return;
        }


        for (int i{index}; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }

            subset.push_back(nums[i]);
            dfs(ans, subset, nums, i + 1);

            subset.pop_back();
        }
    }
};
