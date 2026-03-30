class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Product of Array Except Self to make in O(n) we need to have a prefix and suffix where
        // prefix[i] is the multiplication of all the element previously seen except itself and 
        // the same for suffix[i] but just in opposite direction
        int n(nums.size());
        vector<int> prefix(n, 0), suffix(n, 0), ans(n, 0);
        prefix[0] = 1;
        suffix[n - 1] = 1;

        for (int i{1}; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i];
        }

        for (int i{}; i < n; i++)
        {
            ans[i] = suffix[i] * prefix[i];
        }
        return ans;
    }
};
