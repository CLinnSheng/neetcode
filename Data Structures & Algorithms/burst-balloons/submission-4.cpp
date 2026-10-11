#include <algorithm>
#include <vector>

/*
 * Need to burst all the balloons
 * Bursting ith balloons, receive nums[i - 1] * nums[i] * nums[i + 1]
 * For out of bounds, the value will just be 1
 *
 * Return the maximum number of coins can receive by bursting all the baloons
 *
 * Intuition: We can burst the balloon at any index that we want
 * We can do it in a recursion manner, so we will be passing down the array. And iterate through the array, and try to
 * pop it and find the maximum of it. Every pop will result in two subarray, and we just recursive doing in the two
 * subarray We just treat the recusion function as the reward if this is the last balloon we burst
 *
 * We can improve it by using caching because there is some subproblem being solve multiple time
 * dp[i][j] --> Maximum coin we can get in the range [i, j]
 * */
class Solution
{
  public:
    int maxCoins(std::vector<int> &nums)
    {
        // Push the virtual balloon to the front and back to handle out of bound
        nums.emplace(nums.begin(), 1);
        nums.push_back(1);

        std::vector<std::vector<int>> cache(nums.size(), std::vector<int>(nums.size(), -1));

        return dfs(nums, 1, nums.size() - 2, cache);
    }

    int dfs(std::vector<int> &nums, int left, int right, std::vector<std::vector<int>> &cache)
    {
        // Base Case
        if (left > right)
        {
            return 0;
        }

        if (cache[left][right] != -1)
        {
            return cache[left][right];
        }

        cache[left][right] = 0;

        // Consider left == right also because when there is only one balloon left
        for (int i{left}; i <= right; i++)
        {
            int coins = nums[left - 1] * nums[i] * nums[right + 1];
            coins += dfs(nums, left, i - 1, cache) + dfs(nums, i + 1, right, cache);

            cache[left][right] = std::max(cache[left][right], coins);
        }

        return cache[left][right];
    }
};
