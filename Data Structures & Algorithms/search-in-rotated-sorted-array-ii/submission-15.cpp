#include <vector>
using std::vector;
/*
 * Find the element in the rotated sorted array.
 * Same make use of the sorted array property so that we can find it in log(n) using binary search
 * Just need to find which part to search for.
 * The array is split into 2 increasing parts. Just by comparing the middle element with the last element of the second
 * part, then we can find out which part we need to search for
 * One important thing for htis question is it contains duplicate, so we need to handle duplicate
 * */
class Solution
{
  public:
    bool search(vector<int> &nums, int target)
    {
        int left{}, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            // Handling duplicates
            else if (nums[mid] == nums[right])
            {
                right--;
            }
            // Find the increasing part then check again in the part is it within the range
            else if (nums[mid] < nums[right])
            {
                if (nums[mid] <= target && nums[right] >= target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if (nums[left] <= target && nums[mid] >= target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
