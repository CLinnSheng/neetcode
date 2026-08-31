/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/*
 * Finding the minimum index such that the value is equal to the target
 *
 * Property of the array is a mountain Array
 * which means the first half is asecnding and the second half is descending.
 * So is sorted. We can use binary search since it is sorted.
 * Problem is we dont know where is the peak?
 * So first thing we need to find out the peak. Then we can only do binary search
 * */
#include <algorithm>
#include <climits>
class Solution
{
  public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int left{}, right = mountainArr.length() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
            {
                // On the right side, peak is at index mid or earlier
                right = mid;
            }
            else
            {
                // On the left side, peak is at index mid + 1 or after
                left = mid + 1;
            }
        }

        int peak = left;

        // Once find the peak, binary search on both part
        int index{INT_MAX};
        left = 0;
        right = peak;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int height = mountainArr.get(mid);

            if (height == target)
            {
                index = std::min(index, mid);
                left++;
                right--;
            }
            else if (height > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (index != INT_MAX)
        {
            return index;
        }

        // Second half
        left = peak;
        right = mountainArr.length() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int height = mountainArr.get(mid);

            if (height == target)
            {
                index = std::min(index, mid);
                left++;
                right--;
            }
            else if (height > target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return index == INT_MAX ? -1 : index;
    }
};
