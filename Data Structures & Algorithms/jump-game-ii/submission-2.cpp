/*
Similar to jump game I but with constraint that you can only choose 
the number of jump that is smaller than nums[i]
Brute force way, it just naively explore all paths from index 0 to its reachabele index and continue

Since we want to find the minimum jump
We should be greedy in each index to jump as further as possible
What we can do is in each index, we check how far can we go. Then from within that range we choose the index that can lead to another farthert point
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        } 

        int jumps{};
        int left{}, right{};
        while (right < nums.size() - 1)
        {
            int farthest{};

            for (int index = left; index <= right; index++)
            {
                farthest = std::max(farthest, index + nums[index]);
            }

            left = right + 1;
            right = farthest;
            jumps++;
        }

        return jumps;
    }
};
