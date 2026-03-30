#include <vector>
#include <iostream>

/*
Goal: Search the particular target number in a rotated sorted array
Intuition: For a given number we know that the LHS is smaller than the pivot and RHS is larger
However this doesnt apply all the time because is a rotated array
So we need to find the range it at and then binary search on it
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int left = 0, right = nums.size() - 1;

        while (left <= right) 
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
                return middle;
            // In this range we know is ascending order, therefor we proceed to check whether target lies in it or not
            else if (nums[middle] >= nums[left])
            {
                if (target >= nums[left] && target <= nums[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            // RHS is in ascending order
            else
            {
                if (target >= nums[middle] && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return -1;
    }
};
