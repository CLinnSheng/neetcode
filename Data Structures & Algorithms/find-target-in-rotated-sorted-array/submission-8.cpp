class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{}, right(nums.size() - 1);

        while (left <= right)
        {
            int middle = (left + (right - left) / 2);

            // Determine it at which side
            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] >= nums[left]) // LHS in ascending order
            {
                // Determine at which side
                if (nums[left] <= target && nums[middle] >= target)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else
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
