#include <vector>
using std::vector;
/*
 * Finding the product of array except itself
 * Naive solution double loop.
 * What we can do is maintain a prefix and suffix array. So we can just times with prefix[i] * suffix[i]
 * */
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);

        for (int i{1}; i < n; i++)
        {
            prefix[i] *= prefix[i - 1] * nums[i - 1];
        }

        for (int i{n - 2}; i >= 0; i--)
        {
            suffix[i] *= suffix[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for (int i{}; i < n; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
