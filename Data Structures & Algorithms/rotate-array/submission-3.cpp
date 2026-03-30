class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        std::vector<int> temp(size, 0);

        for (int i{} ; i < size; i++)
        {
            int pos = (i + k) % size;
            temp[pos] = nums[i];
        }

        nums = temp;
    }
};