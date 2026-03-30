class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); 
        cout.tie(nullptr);

        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
            if (map.count(target - nums[i]))
                return {map[target - nums[i]], i};
            else
                map[nums[i]] = i;

        return {-1, -1};
    }
};
