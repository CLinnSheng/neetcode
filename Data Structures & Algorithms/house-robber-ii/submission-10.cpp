class Solution {
public:
    int rob(vector<int>& nums) {
       // Similar to house robber I, but now first house and last house is neighbor
       // So what we can do is split into 2 question but using the same logic 

       // Edge case
       if (nums.size() == 1)
       {
        return nums[0];
       }
       std::vector<int> nums1(nums.begin(), nums.end() - 1), nums2(nums.begin() + 1, nums.end());
       return std::max(rob_2(nums1), rob_2(nums2));
    }

    int rob_2(const std::vector<int>& nums)
    {
        std::vector<int> cache(nums.size(), -1);
        return dfs(0, nums, cache);
    }

    int dfs(const int index, const std::vector<int>& nums, std::vector<int>& cache)
    {
        if (index >= nums.size())
        {
            return 0;
        }

        if (cache[index] != - 1)
        {
            return cache[index];
        }

        return cache[index] = std::max(dfs(index + 1, nums, cache), nums[index] + dfs(index + 2, nums, cache));
    }
};
