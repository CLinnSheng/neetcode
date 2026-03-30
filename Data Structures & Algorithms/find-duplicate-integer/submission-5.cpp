/*
An array of integers nums containing n + 1 integers. Each integer is in the range of [1, n]
Goal: Find the duplicate number

Intution:
The easiest way and most efficient way is straight away is using hash set.
But this will take space complexity: O(n)

can we optimize it to O(1)?
Ok from the question the array containing n + 1 integers but is in the range of [1, n].
Then that's mean there def have repeating elements.
We can treat each element as a node. So got repeating elements mean got cycle like pointed to the same node
We can use the fast and slow pointer approach.
But this will only detect cycle.
Actually the fast ptr tell us the entry of the cycle.
So we will just have to iterate from the beginning for the slow ptr when they meet agn
this is the repeating val
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // Time & Space: O(n)
        // std::unordered_set<int> set;
        // for (const auto& num : nums)
        //     if (set.count(num))
        //         return num;
        //     else
        //         set.insert(num);

        // return -1;

        // Space: O(1)
        int fast{nums[0]}; // Move by 2 nodes
        int slow{nums[0]}; // Move by 1 node
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];

            if (fast == slow)
                break;
        }
        
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
