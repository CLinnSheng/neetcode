class Solution {
public:
// Intuition: Return an array where i is the product of all the element except the element i in nums
// Constraint: Must be O(n)
// We can find the prefix sum and the postfix sum of every single element
// THen output[i] = prefix[i] + postfix[i]
    vector<int> productExceptSelf(vector<int>& nums) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int size = nums.size();

        vector<int> ans(size, 1);
        int prefix = 1;
        int postfix = 1;

        // Prefix
        for (int i = 0; i < size; i++){    
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Postfix
        for (int i = size - 1; i >= 0; i--){
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};
