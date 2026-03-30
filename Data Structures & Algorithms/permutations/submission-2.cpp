#include <functional>
#include <vector>
using std::vector;

/*
 * Goal: Return all possible permuations
 *
 * Intuition:
 * Permutation means all the number must be in use but in any order
 * so we need an array to track whether this number is used or not
 * AS usual we can just use backtracking to try all possible combinations
 * Time Complexity: O(n! * n)
 * */
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n(nums.size());

        if (n == 0)
            return {};

        vector<vector<int>> answer;
        vector<int> currSubset;
        vector<int> used(n, false);

        std::function<void()> backtracking = [&]() {
            if (currSubset.size() == n)
            {
                answer.emplace_back(currSubset);
                return;
            }

            for (int i{}; i < n; i++)
            {
                if (used[i])
                    continue;

                currSubset.emplace_back(nums[i]);
                used[i] = true;
                backtracking();

                // backtracking
                currSubset.pop_back();
                used[i] = false;
            }
        };
        backtracking();
        return answer;
    }
};
