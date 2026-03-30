/*
Straight forward approach is stored everything in a hash map.
O(n) for both time & space complexity

But how can achieve O(1) space complexity?
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int size = nums.size();
        std::unordered_map<int, int> map;

        for (const auto num : nums)
        {
            map[num]++;
        }

        std::vector<int> ans;

        for (const auto &[val, cnt]: map)
        {
            if (cnt > size / 3)
            {
                ans.push_back(val);
            }
        }
        return ans;
    }
};