#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using std::vector;
/*
 * Sorted array. Return the k closest integers to x in the array.
 * Okay the question is kinda fixed on the size of array to return. Then we can easily implement the sliding window algo
 * with fixed size k. Every loop we just shrink and expand once
 * Then how do we determine the `closest` for multiple element? Just get the abs sum
 * */

class Solution
{
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        if (k >= n)
        {
            return arr;
        }

        int left{}, right{k - 1};
        int sum{};
        for (int i{}; i <= right; i++)
        {
            sum += std::abs(x - arr[i]);
        }
        std::unordered_map<int, vector<int>> map;
        map[sum] = std::vector<int>(arr.begin(), arr.begin() + k);

        while (right < n - 1)
        {
            sum -= std::abs(arr[left] - x);
            sum += std::abs(arr[right + 1] - x);

            left++;
            right++;

            if (map.find(sum) == map.end())
            {
                map[sum] = std::vector<int>(arr.begin() + left, arr.begin() + left + k);
            }
        }

        int min_diff{INT_MAX};
        for (const auto &[diff, _] : map)
        {
            min_diff = std::min(min_diff, diff);
        }

        return map[min_diff];
    }
};
