/*
Intuition: This will be a little bit similar to the prev question of finding
the minimum in rotated sorted array. For this we just need a little bit of tweak.
For this time we need to find in which part will be the target be.
So the 2 part is actually sorted as well but this is not always the case. So we have to find out
which part is sorted in ascending order then check whether target is within the range or not
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{}, right(nums.size() - 1);

        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (nums[middle] == target)
                return middle;
            else if (nums[middle] >= nums[left]) // LHS in ascending order
            {
                // Check within the range or not
                if (nums[left] <= target && nums[middle] >= target)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else // RHS in ascending order
            {
                if (nums[middle] <= target && nums[right] >= target)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }  
        return -1;
    }
};
