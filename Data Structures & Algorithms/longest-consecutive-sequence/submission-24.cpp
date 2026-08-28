#include <unordered_set>
#include <vector>
using std::vector;
/*
 * Naive solution is by treating every single num as the starting number and then try to loop until the constraint
 * Or we can just simply sort it.
 * Key observation from 2 of the approach above, we need the starting number.
 * Why not we just focus on finding the starting number in the array?
 * So we dont have to iterate through each nubmer every single time, instead just the starting number is good enough
 * */
class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int ans{};

        for (auto num : nums)
        {
            // Check whether is it the starting number
            if (set.find(num - 1) == set.end())
            {
                int cnt{1};

                // Loop it
                while (set.find(num + 1) != set.end())
                {
                    cnt++;
                    num++;
                }

                std::cout << num << '\t' << cnt << '\n';
                ans = std::max(ans, cnt);
            }
        }

        return ans;
    }
};
