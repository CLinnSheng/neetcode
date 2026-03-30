#include <unordered_map>
#include <vector>
/*
 * Given integer array of size n
 * Goal: Find all elements that appear more than n/3 times
 *
 * Intuition:
 * The simplest method is to track the frequency of each element by using a hash map
 * Then iterate through the map and find all that n/3 times
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution
{
  public:
    std::vector<int> majorityElement(std::vector<int> &nums)
    {
        int n(nums.size());

        std::vector<int> ans;

        std::unordered_map<int, int> freq;
        for (const auto &num : nums)
            freq[num]++;

        for (const auto &[val, cnt] : freq)
            if (cnt > (n / 3))
                ans.emplace_back(val);

        return ans;
    }
};
