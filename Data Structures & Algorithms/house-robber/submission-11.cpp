class Solution {
public:
    int rob(vector<int>& nums) {
        // Cannot rob 2 adjacent house
        // Find the maximum amount of money that i can rob wihtout alerting
        // So at each step we can either choose to rob or not --> recursive
        // If we notice from the recursive, at some index we are doing the repetitive works
        // we can further improve it by using caching O(2^n) -> O(n^2)
        std::vector<int> cache(nums.size(), -1);
        return dfs(0, nums, cache);
        
    }

    int dfs(const int index, const std::vector<int>& nums, std::vector<int>& cache)
    {
        if (index >= nums.size())
        {
            return 0;
        }

        if (cache[index] != -1)
        {
            return cache[index];
        }


        // Skip or choose current house
        int sum = std::max(dfs(index + 1, nums, cache), nums[index] + dfs(index + 2, nums, cache));

        return cache[index] = sum;
    }
};
