#include <algorithm>
#include <climits>
#include <vector>
/*
 * Return the maximum possible sum of non-empty subarray of nums.
 * Take note that the array is circular means that we can wrap around
 *
 * Brute force will jsut simply be trying all possible subarray and finding the maximum Sum
 * Time Complexity: O(n^2)
 *
 * Observation from the brute force approach. We found that computing each subarray sum is kinda repetitive how can we
 * do it in a single loop? because it just simply add more new element when we looping. So obviously we need to do it in
 * a single pass. So we might need to cache the previous result and just sum with current index
 *
 * So at each index we have 2 choices, either extend from the previous Subarray or starting a new subarray
 * maxSum = max(maxSum + x, x);
 * But we are not done because the array is circular
 * We need to find what if we can wrap arround and the subarray we happen to find is at the end
 * So this leave us a contiguous section between the prefix and suffix
 * example: -2 4 -5 4 -5 9 4. Where we only want ['-2','4', ., ., ., '9', '4']
 * In another way the contiguous section will just simply be the smallest possible sum in the array
 * So the sum will just simply be the totalSum minus with the min Sum
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int maxSubarraySumCircular(std::vector<int> &nums)
    {
        int n = nums.size();
        int maxSum{INT_MIN}, currMax{};
        int minSum{INT_MAX}, currMin{};
        int ttlSum{};

        // Brute force
        // for (int i{}; i < n; i++)
        // {
        //     int currSum{};
        //     for (int j{i}; j < i + n; j++)
        //     {
        //         currSum += nums[j % n];
        //         maxSum = std::max(maxSum, currSum);
        //     }
        // }

        for (const auto num : nums)
        {
            ttlSum += num;

            currMax = std::max(num, currMax + num);
            maxSum = std::max(maxSum, currMax);

            currMin = std::min(num, currMin + num);
            minSum = std::min(minSum, currMin);
        }

        // Handle edge cases when all eleemnts are negative
        if (maxSum < 0)
        {
            return maxSum;
        }

        return std::max(ttlSum - minSum, maxSum);
    }
};
