#include <algorithm>
#include <vector>
using std::vector;
/*
 * Find the indices such that they sum up to 0
 * We can sort it up first, so if we encounter the first index > 0 then can prune
 * We can use 2sum method but this time, one number is fixed
 * */
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i{}; i < n - 2; i++)
        {
            // Handle duplicate
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int fixed{nums[i]};
            if (fixed > 0)
            {
                break;
            }

            int left{i + 1}, right{n - 1};

            while (left < right)
            {
                int sum = fixed + nums[left] + nums[right];

                if (sum == 0)
                {
                    ans.push_back({fixed, nums[left], nums[right]});
                    left++;

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return ans;
    }
};
