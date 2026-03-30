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
        std::unordered_map<int, int> map;
        for (const auto num : nums)
        {
            if (map.count(num))
                return true;
            map[num]++;
        }
        return false;
    }
};
