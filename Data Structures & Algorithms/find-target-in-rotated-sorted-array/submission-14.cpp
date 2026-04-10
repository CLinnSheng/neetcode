class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Finding the target in a rotated sorted array
        // sorted array -> can make use of binary search
        // Rotated --> Condition on checking binary search will be diff
        // Check on which side is smaller through checking the middle element with the lsat elment

        int n = nums.size();
        int left{}, right{n - 1};

        // Since we finding the exact number we use left <= right [Normally!]
        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
            {
                return middle;
            }
            // Check which side is sorted
            else if (nums[middle] <= nums[right])
            {
                if (nums[middle] <= target && target <= nums[right])
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
            else
            {
                if (nums[middle] >= target && target >= nums[left])
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
        }
        return -1;
    }
};
