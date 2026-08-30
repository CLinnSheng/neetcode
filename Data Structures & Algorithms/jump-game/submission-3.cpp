/*
Check whether we can jump from index 0 to the last index
Brute force way it just try all possible jump at each index until we found one or cannot jump at all
Time Complexity: O(n!)

How can we further optimize it to O(n) or (nlgn) or O(n^2)
Since we cant really do any sorting so O(nlgn) is remove
Then we can only do O(n)
Ok observe from the O(n!)
O(n) looping through the nums and then from here we trying all possible jump at this index
What we can optimize over ehre is just the trying all possible jump
So instead of trying all possible jump how can we know which jump should i go for from 0 <= x <= nums[i] at index i?

O(n^2) is probably using dp

How about we being greedy when making decision? Why dont we always chooose the largest step?
Actually instead of starting from index 0, starting from the back is actually easier
So we start from index = n - 2. We check whether can we reach n - 1. If we can means that we only need to check we can reach n - 2 or not? Because once we can reach n - 2 then definitely we can reach n - 1
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size(); 
       if (n == 1)
       {
            return true;
       }

        int goal = n - 1;

        for (int index{n - 2}; index >= 0; index--)
        {
            if (index + nums[index] >= goal)
            {
                goal = index;
                continue;
            }
        }

        return goal == 0;
    }
};
