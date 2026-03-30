/*
Goal: Find the duplicate number

Intution:
The easiest way and most efficient way is straight away is using hash set.
But this will take space complexity: O(n)
can we optimize it to O(1)?


*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> set;
        for (const auto& num : nums)
            if (set.count(num))
                return num;
            else
                set.insert(num);

        return -1;
    }
};
