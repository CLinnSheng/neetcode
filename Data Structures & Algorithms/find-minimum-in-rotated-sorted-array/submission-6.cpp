/*
Goal: Find the minimum element in the array

Intuition:
The array is sorted but is in a rotated manner.
The brute force way will be linear search.
If you observe the array carefully, u can actually see the array is seperated into 2 parts.
eg: 3, 4, 5, 6, 1, 2 --> 3, 4, 5 & 6, 1, 2
So we can see the smallest element always on the unsorted half
*/
class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int left{}, right(nums.size() - 1);

        while (left < right)
        {
            int middle(left + (right - left) / 2);

            if (nums[middle] > nums[right])
                left = middle + 1;
            else
                right = middle;
        }    
        return nums[left];
    }
};
