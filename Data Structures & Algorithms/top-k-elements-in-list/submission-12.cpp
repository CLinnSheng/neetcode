#include <unordered_map>
#include <vector>
using std::vector;
/*
 * Finding the top k element
 * Several Ways
 * 1. Using MaxHeap or Sorting
 * O(nlgn)
 *
 * 2. Bucket sorting
 * So how bucket sorting works is we push the number according to their freq, each bucket represent a freq
 * */
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        std::unordered_map<int, int> freq;
        for (const auto &num : nums)
        {
            freq[num] = 1 + freq[num];
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &[num, freq] : freq)
        {
            bucket[freq].push_back(num);
        }

        // Find from the most freq bucket first
        vector<int> ans;
        for (int i = nums.size(); i > 0; i--)
        {
            int bucket_size = bucket[i].size();
            for (int j{}; j < bucket_size && k > 0; j++, k--)
            {
                ans.push_back(bucket[i][j]);
            }

            if (k == 0)
            {
                return ans;
            }
        }

        return ans;
    }
};
