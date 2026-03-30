class Solution {
public:
    int rob(vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        size_t n_house = nums.size();
        if (n_house == 0) return 0;
        if (n_house == 1) return nums[0];

        nums[1] = std::max(nums[1], nums[0]);

        for (int i = 2; i < n_house; i++)
            nums[i] = std::max(nums[i - 1], nums[i] + nums[i - 2]);
        return nums[n_house - 1];
    }
};
