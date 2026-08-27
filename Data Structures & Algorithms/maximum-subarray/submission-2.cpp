/*
Finding the contiguous subarray with the largest sum and return the sum
Okay, so at every index we have 2 choices
Include it or skip it --> Decision Tree but with some tweats because it neede contiguous subarray
once we take it then we can only include the next element or stop taking any more new element
So we can solve it naively through recursion and we important thing we need to pass is a flag to keep track of whether has we form a subarray or not
Time Complexity: O(2^n)

Observation from the recursion
We can see subproblem is solved multiple time. Why  dont we cahce it and reuse
2 things that are passed down the recursion which is the index and also whether has subarray build or not?
so dp[i][j] --> Maximum subarray sum start from i where subarray is built or not depends on value j
Time Complexity: O(n)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>>dp (nums.size(), vector<int>(2, -1));
        return recursive(nums, 0, false, dp);
    }

    int recursive(const std::vector<int>& nums, const int index, bool flag, vector<vector<int>>& dp)
    {
        // Base case
        if (index == nums.size() -1)
        {
            return flag ? std::max(0, nums[index]) : nums[index];
        }

        if (dp[index][flag] != -1)
        {
            return dp[index][flag];
        }

        // If subarray already built
        // Choose the maximum between continuing the subarray or stop at here
        if (flag)
        {
            // Include the current val or just continue to skip it
            return dp[index][flag] = std::max(nums[index] + recursive(nums, index + 1, flag, dp), 0);
        }

        // Havent built subarray
        // Choose the maximum starting from here or not
        return dp[index][flag] = std::max(nums[index] + recursive(nums, index + 1, true, dp), recursive(nums, index + 1, false, dp));
    }

};
