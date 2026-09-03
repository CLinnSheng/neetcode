#include <algorithm>
#include <vector>
using std::vector;
/*
 * Return a list of all unique combination
 * Since mention all combination --> Trying all possible ways --> Backtracking
 * Since it meantion can be any order, we can sort it first to make life easier
 * */
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> subsset;

        std::sort(candidates.begin(), candidates.end());

        dfs(candidates, ans, subsset, target, 0, 0);

        return ans;
    }

    void dfs(const vector<int> &candidates, vector<vector<int>> &ans, vector<int> &subset, int target, int index,
             int currSum)
    {
        if (index == candidates.size() && currSum != target)
        {
            return;
        }

        if (currSum == target)
        {
            ans.push_back(subset);
            return;
        }

        for (int i{index}; i < candidates.size(); i++)
        {
            if (candidates[i] + currSum > target)
            {
                break;
            }

            // Handling duplicate
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            subset.push_back(candidates[i]);
            dfs(candidates, ans, subset, target, i + 1, currSum + candidates[i]);

            subset.pop_back();
        }
    }
};
