#include <vector>
using std::vector;
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        vector<bool> include(nums.size(), false);

        dfs(nums, subset, ans, include);
        return ans;
    }

    void dfs(const vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans, vector<bool> &include)
    {
        if (subset.size() == nums.size())
        {
            ans.push_back(subset);
            return;
        }

        for (int i{}; i < nums.size(); i++)
        {
            if (include[i] == false)
            {
                include[i] = true;
                subset.push_back(nums[i]);
                dfs(nums, subset, ans, include);

                include[i] = false;
                subset.pop_back();
            }
        }
    }
};
