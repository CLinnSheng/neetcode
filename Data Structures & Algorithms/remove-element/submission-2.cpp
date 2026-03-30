class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k{};

        for (int i{}; i < nums.size(); i++)
        {
            // Replace within the array
            if (nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};