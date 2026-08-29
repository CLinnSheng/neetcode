#include <algorithm>
#include <vector>
using std::vector;
/*
 * Find the indices such that they sum up to 4
 * We can sort it up first, so if we encounter the first index > 0 then can prune
 * We can use 2sum method  and 3sum method but this time, two number is fixed
 * So 1 loop through nums and another loop is doing 3 sum
 * */
class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 4)
        {
            return {};
        }

        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i{}; i < n - 3; i++)
        {
            int first{nums[i]};

            // Handle duplicate
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j{i + 1}; j < n - 2; j++)
            {
                int second{nums[j]};

                // Handle duplicate
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left{j + 1}, right{n - 1};

                while (left < right)
                {
                    long long sum = (long long)first + second + nums[left] + nums[right];

                    if (sum == target)
                    {
                        ans.push_back({first, second, nums[left], nums[right]});
                        left++;

                        while (left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};
