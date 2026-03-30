class Solution {
public:
// Intuition: Return the k most frequent element
// Use hash map to find out the count of each number
// Use another array to reverse the key and value pair of hash
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); 
        cout.tie(nullptr);

        unordered_map<int, int> count;

        for (auto &i : nums)
            count[i]++;


// Another array to store the other way around of hash table
        vector<vector<int>> freq(nums.size() + 1);

        for (auto [_first, _second] : count)
            freq[_second].push_back(_first);
        
// Since want to find the top k element
// We start from behind until size - k
        vector<int> ans;
        for (int i = freq.size() - 1; i >= 1; i--){
            for (auto &j : freq[i])
                ans.push_back(j);
            if (ans.size() == k)
                return ans;
        }

        return {};
    }
};
