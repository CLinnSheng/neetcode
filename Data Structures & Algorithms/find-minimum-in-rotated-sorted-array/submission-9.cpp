class Solution {
public:
    int findMin(vector<int> &nums) {
        // The array is sorted but is in rotated manner
        // So we need to find out the front part of the array
        // Which we can easily find out by comparing the middle element with the last element
        // if the middle element > last element
        //  - means the right half is smaller, so it contains the minimum elment

        int n = nums.size();
        int left{}, right{n - 1};

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            // Find out the smaller part
            if (nums[middle] > nums[right])
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        return nums[left];
    }
};
