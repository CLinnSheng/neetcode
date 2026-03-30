/*
Subarray & Order does Matter --> Sliding Window Algo
Finding minimum length such that sum is target
Brute Force is by iterate it twice --> O(n^2)
Optimize it is either O(nlgn) or O(n)
So the only choice is O(n) and we have to iterate it once

Problem --> How do we decide when to move the window?
Keep moving right until it is greater or equal to the target. Then start to move left until is smaller than target
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        // Base Case       
        if (std::accumulate(nums.begin(), nums.end(), 0) < target)
        {
            return 0;
        }
        
        int ans{INT_MAX};
        int size = nums.size();
        int left{}, right{}, currSum{};

        while (right < size)
        {
            // Include current number
            currSum += nums[right];

            // Check Window && Shrink
            while (left <= right && currSum >= target)
            {
                ans = std::min(ans, right - left + 1);
                currSum -= nums[left];
                left++;
            }

            right++;
        }

        return ans == INT_MAX? 0 : ans;
    }
};