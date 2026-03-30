/*Intuition: Since want to find duplication across an array of elements
We can use hash map data structure to store the frequency of each char and then iterate through the hash
*/
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> map;

        for (auto &num : nums)
            map[num]++;

        for (auto &[key, val] : map)
            if (val > 1)
                return true;

        return false;
    }
};
