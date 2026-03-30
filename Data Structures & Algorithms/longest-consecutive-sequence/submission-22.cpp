#include <algorithm>
#include <unordered_set>
#include <vector>

/*
 * Given an unsorted array
 * Goal: Return the length of the longest consecutive element sequence.
 * Eg: [100, 4, 200, 1, 3, 2]
 * longest consecutive element will be [1, 2, 3, 4]
 *
 * Intuition:
 * Key important observation from the example is we dont have to follow the order of original element.
 * We just need to find all the possible consecutive element sequence.
 * So we need to know about the information of all the elements available in the array.
 * We can store it in a set. Then brute force it by trying from all the possible elements in the array. -1e9 <= nums[i]
 * <= 1e9. But this is super inefficient. Is there any way to optimize this? Yes instead of trying all possible integer,
 * why dont we just try all possible integer in the array only? How can we do this inefficiently? We can sort the array
 * first and then check whether is this elmeent the first element of a sequence in the array or not
 * we also need to take care of the same element in the array, so we simply just skip it
 * Time Complexity:
 * O(nlgn)
 * But how can we further optimize it to O(n)? So this means that we acnnot do sorting and only way is to iterate through teh array?
 * How iterating the array can find the longest consecutive sequence? We need to know whetehr the next element is in the array or not.
 * This means that we need to store all the value in a hash set because we can access it in O(1). And more optimize is to only iterate if the element is the first element in a sequence
 * */
class Solution
{
  public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int ans{};

        for (auto num : nums)
        {
            // Only consider if is the first element
            if (set.count(num - 1))
            {
                continue;
            }

            // If is the first element then iterate
            int len{1};
            while (set.count(num + 1))
            {
                len++;
                num++;
            }
            
            ans = std::max(ans, len);
        }
        return ans;
    }
};
