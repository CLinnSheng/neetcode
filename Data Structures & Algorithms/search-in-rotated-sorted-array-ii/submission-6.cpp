/*
Intuition:
This 1 the approach will be the same as version I.
We also need to find out at which part target will be at, then keep dividing by half through
binary search
But with some tweak, because now the array has duplicate we can no longer compare like
this nums[middle] >= nums[left] because we can no longer ensure the part is sorted
for eg, [1, 0, 1, 1, 1] now nums[middle] == nums[left] == nums[right]
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left{}, right(nums.size() - 1);

        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (nums[middle] == target)
                return true;

            if (nums[middle] == nums[left])
                left++;
            else if (nums[middle] > nums[left])
            {
                if (nums[middle] > target && nums[left] <= target)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else
            {
                if (nums[middle] < target && nums[right] >= target)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return false;
    }
};