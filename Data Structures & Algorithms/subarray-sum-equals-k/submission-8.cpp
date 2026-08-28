#include <unordered_map>
#include <vector>
using std::vector;
/*
 * Finding the number of contiguous subarray such that it is equal to k
 * Brute force will just simply naively double loop it --> O(n^2)
 * Can we further optimize it? Cannot sort since order is important
 * Reduce the loop to 1?
 * Then need to save information about the array
 * Finding the prefix so we can reuse it
 * So what can we do with the prefix.
 * We can actually store the number of freq with this prefix before i.
 * Then we can easily find the sum of a subarray by prefix[j] - prefix[i] = sum[i + 1: j]
 * Thus we just need to find currSum - k
 * O(n)
 * */
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans{}, currSum{};
        std::unordered_map<int, int> prefix;
        prefix[0] = 1; // Only 1 way to get prefix 0 which is include nothing at the start

        for (const auto num : nums)
        {
            currSum += num;
            int diff = currSum - k;

            // Finding how many contiguous subarray with `diff`
            ans += prefix[diff];

            prefix[currSum]++;
        }

        return ans;
    }
};
