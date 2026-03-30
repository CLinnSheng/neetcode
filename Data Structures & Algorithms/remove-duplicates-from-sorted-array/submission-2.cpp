class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Use 2 pointer
        // 1 pointer represent the next elmeent to be place and another pointer is to find the next unique element
        int left{}, right{};

        while (right < nums.size())
        {
            nums[left] = nums[right];

            while (right < nums.size() && nums[right] == nums[left])
            {
                right++;
            }
            left++;
        }
        return left;
    }
};