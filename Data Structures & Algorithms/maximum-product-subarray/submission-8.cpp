class Solution {
public:
    int maxProduct(vector<int>& nums) {
       // Naive approach will be trying all possible substring 
       // O(n^2)
       // Precompute the suffix and prefix
       // Negative * Negative --> Positive
        int prefix{}, suffix{};
        int ans{nums[0]};
        int n = nums.size();

        for (int i{}; i < n; i++)
        {
            prefix = nums[i] * (prefix == 0? 1 : prefix);
            suffix = nums[n - i - 1] * (suffix == 0? 1 : suffix);

            ans = std::max(ans, std::max(prefix, suffix));
        }
        
        return ans;
    }
};
