class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left{}, right{}, sum{};
        int ans{INT_MAX};

        while (right < n)
        {
            sum += nums[right];

            while (left <= right && sum >= target)
            {
                ans = std::min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }
        return ans == INT_MAX? 0 : ans;        
    }
};