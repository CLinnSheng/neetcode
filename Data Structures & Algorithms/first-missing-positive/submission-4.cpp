#include <utility>
#include <vector>

/*
 * Nums is unsorted.
 * Goal: Return the smallest positive integer that is not present in nums
 * Constraint: Time Comeplexity O(N) & Space Complexity: O(1)
 *
 * Intuition:
 * We only care about positive integer.
 * Important observation: is the maximum missing positive will be n + 1
 * and then the minimum will be 1
 * */
class Solution
{
  public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        // 1. First Approach O(n)
        // Use an array to keep track of all the available elements

        // int n(nums.size());
        // std::vector<int> seen(n, false);
        //
        // for (const int &num : nums)
        //     if (num > 0 && num <= n)
        //         seen[num - 1] = true;
        //
        // for (int i{}; i < n; i++)
        //     if (!seen[i])
        //         return i + 1;
        //
        // return n + 1;

        // How can we optimize the space to O(1)?
        // O(1) is either uses a variable or apply the logic in existing space.
        // We can sort the nums but in O(n) time complexity
        // The way to apply in existing space, is the same as how we use the extra space
        // so nums[i] should be i + 1

        int n(nums.size());

        int i{};
        while (i < n)
        {
            // Place the integer at the correct position like the 1 in O(n)
            // 1 --> nums[0]
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                std::swap(nums[nums[i] - 1], nums[i]);
            else
                i++;
        }

        for (i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
