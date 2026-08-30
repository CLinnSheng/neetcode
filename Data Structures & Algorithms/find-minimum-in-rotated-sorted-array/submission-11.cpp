#include <vector>
using std::vector;
/*
 * Finding the minimum element in the roated sorted array
 * Ok so the array in someway is also sorted, how can we make use of it sorted property?
 * If we can find out then we can easily find the minimum in log(n) with binary search
 * If you observe from the array there is 2 part in the array. Both part is increasing
 * But the smallest number in the first part
 * */
class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int left{}, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                // Smallest number is in the right
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return nums[left];
    }
};
