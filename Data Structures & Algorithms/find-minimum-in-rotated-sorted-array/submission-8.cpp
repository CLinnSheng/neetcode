class Solution {
public:
    int findMin(vector<int> &nums) {
        int n(nums.size());
        int left{}, right{n - 1};

        while (left < right)
        {
            int middle = (left  + (right - left) / 2);

            if (nums[middle] < nums[right]) // min element is the first element in the rotated sorted array so its in the left
            {
                right = middle;               
            }
            else
            {
                left = middle + 1;
            }
        }
        return nums[left];
    }
};
