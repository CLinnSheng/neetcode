#include <set>
#include <vector>

/*
 * nums is sorted in ascending order, remove the duplicates in-place such that each unique element appear only once.
 * Relative order should be kept the same.
 * Consider the number of unique elements of nums are k:
 * i. Change the array nums such that the first k elements of nums contain the unique elements in the order they were
 * present in nums initially. Remaining elements of nums are not important as well as the size of nums. Goal: Return k.
 *
 * Eg: nums = [1,1,2]
 * Output: 2 & nums --> [1,2,_]
 *
 * Intuitoin:
 * The most straightaway approach is by using a set which kept the element in sorted manner
 * but this will take time complexity of O(nlgn)
 * */
class Solution
{
  public:
    int removeDuplicates(std::vector<int> &nums)
    {
        // Time Complexity: O(nlgn)
        std::set<int> elements;
        for (int i{}; i < nums.size(); i++)
            elements.insert(nums[i]);

        nums.resize(elements.size());
        int i{};
        for (const int &element : elements)
            nums[i++] = element;

        return elements.size();
    }
};
