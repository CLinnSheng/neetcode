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
An array is mountain if
i. arr.length >= 3
ii. arr[0] < arr[1] < .. < arr[i] & arr[n] > arr[n - 1] > .. > arr[i + 1]
Goal: Return the minimum index such that mountainArr.get(index) == target. else return -1

Intuition:
The brute force will just scna through the array and check whether the value is equal to target or not
This will in O(n)

But can we further optimize it? the only possible time complexity is O(1) & O(lgn)
O(lgn) will be using binary search. But how do we apply binary saerch on this?
Ok so we gonna find the peak first because the peak will partition the array into 2 half 1 in ascending and another in descending order
Then we can apply the binary search on these 2 array. But how do we find the peak?
we can actually use binary search to find the peak as well
*/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len(mountainArr.length());

        // Find Peak
        int left{1}, right{len - 2}; // Because peak wont be at the edges
        int peak{};
        while (left <= right)    
        {
            int m(left + (right - left) / 2);
            int leftM{mountainArr.get(m - 1)}, middle{mountainArr.get(m)}, rightM{mountainArr.get(m + 1)};

            if (leftM < middle && middle < rightM)
                left = m + 1;
            else if (leftM > middle && middle > rightM)
                right = m - 1;
            else
            {
                peak = m;
                break;
            }
        }

        // Binary Search on Left Partition (Ascending)
        left = 0;
        right = peak - 1;
        while (left <= right)
        {
            int middle(left + (right - left) / 2);
            int middleVal{mountainArr.get(middle)};

            if (middleVal > target)
                right = middle - 1;
            else if (middleVal < target)
                left = middle + 1;
            else
                return middle;
        }

        // Binary Search on right partition (Descending)
        left = peak;
        right = len - 1;
        while (left <= right)
        {
            int middle(left + (right - left) / 2);
            int middleVal{mountainArr.get(middle)};
            
            if (middleVal > target)
                left = middle + 1;
            else if (middleVal < target)
                right = middle - 1;
            else
                return middle;
        }

        return -1;
    }
};