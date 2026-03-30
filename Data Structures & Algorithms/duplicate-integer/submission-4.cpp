#include <unordered_set>
#include <vector>

/*
 * Goal: Check whether is there any duplicate in the array
 *
 * Intuition:
 * The most straightaway is store the val visited in the hash set
 * Time & Space Complexity: O(n)
 *
 * But can we further improve the space complexity to O(1)
 * */
class Solution
{
  public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> set;

        for (const auto &num : nums)
            if (set.count(num))
                return true;
            else
                set.insert(num);

        return false;
    }
};
