#include <vector>
/*
 * Find the length of maximum size turbulent array
 * Turbulent -> The height keep changing up and down
 * Brute force solution is just loop through all the possible subarray
 * Or another way is just through recursive
 * From recursive we see subproblem is being solved multiple times then just cache it and reuse
 * */
class Solution
{
  public:
    int maxTurbulenceSize(std::vector<int> &arr)
    {
        int maxLen{1};
        std::vector<std::vector<int>> cache(arr.size(), std::vector<int>(2, -1));

        for (int i{}; i < arr.size(); i++)
        {
            // Try to start from every index
            maxLen = std::max(maxLen, recursive(arr, i, true, cache));
            maxLen = std::max(maxLen, recursive(arr, i, false, cache));
        }

        return maxLen;
    }

    int recursive(const std::vector<int> &arr, int index, bool pos, std::vector<std::vector<int>> &cache)
    {
        // Base case
        if (index == arr.size() - 1)
        {
            return 1;
        }

        if (cache[index][pos] != -1)
        {
            return cache[index][pos];
        }

        if ((pos && arr[index] > arr[index + 1]) || (!pos && arr[index] < arr[index + 1]))
        {
            return cache[index][pos] = 1 + recursive(arr, index + 1, !pos, cache);
        }

        return cache[index][pos] = 1;
    }
};
