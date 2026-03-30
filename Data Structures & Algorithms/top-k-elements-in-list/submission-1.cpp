class Solution {
public:
// Intuition: Find the k most frequent elements
// Use Hash to find out the count of every single element first

    vector<int> topKFrequent(vector<int>& nums, int k) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> count;

        int size = nums.size();

        for (auto &num : nums)
            count[num]++;

        vector<int> ans;

        // Reverse the key and value
        // Mow key is the count and value is the element
        // use 2d in case some element hsa the same count
        vector<vector<int>> freq(size + 1);
        for (auto [_val, cnt] : count)
            freq[cnt].push_back(_val);

        for (int i = size; i >= 1; i--)
            for (auto &vec : freq[i]){
                ans.push_back(vec);    
                if (ans.size() == k)
                    return ans;
            }    
        
        return {};

    }
};
