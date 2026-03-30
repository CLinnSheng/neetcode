/*
Find 2 indices such that nums[i] == nums[j]
and the differences must be abs(i - j) <= k
we can have a sliding window that make sure is always within k and move the left pointer whenever go out of k
How do we check within the window? just use hash set, is much more easier
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int size = nums.size();
        if (size == 1)
        {
            return false;
        }

        int left{}, right{1};
        std::unordered_set<int> vals;
        vals.insert(nums[left]);

        while (right < size)
        {
            if (vals.count(nums[right]))
            {
                return true;
            }

            if (vals.size() == k)
            {
                vals.erase(nums[left]);
                left++;
            }

            vals.insert(nums[right]);
            right++;
        }    
        return false;
    }
};