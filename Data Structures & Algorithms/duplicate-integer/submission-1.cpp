class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_set<int> set;

        for (auto &i : nums)
            if (set.count(i))   return true;
            else set.insert(i);

        return false;
    }
};
