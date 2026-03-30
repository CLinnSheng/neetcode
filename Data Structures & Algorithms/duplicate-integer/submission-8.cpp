#include <unordered_set>
#include <vector>

/*
 * Goal: Check whether is there any duplicate in the array
 *
 * Intuition:
 * The most straightaway is store the val visited in the hash set
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> seen;
        for (const auto num : nums)
        {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;
    }
};
