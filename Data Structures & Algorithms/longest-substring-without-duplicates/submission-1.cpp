class Solution {
public:
// Since we want to find a longest substring within a array
// We can use sliding window algo to find

// Have two pointer which is left and right
// Keep updating the right while meeting the condition which is no repeat
// If kena repeat then we only update the left one until no repeat
    int lengthOfLongestSubstring(string s) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_set<int> repeat;

        int left = 0, right = 0;
        int size = s.size();
        int length = INT_MIN;

        if (!size)  return 0;
        
        for (; right < size; right++){
        // if no duplicates
            if (!repeat.count(s[right]))
                // keep updating the length
                length = max(length, right - left + 1);
        
        // if found duplicates, then we keep move left until no duplicate
            else
                while (repeat.count(s[right]))
                    repeat.erase(s[left++]);

            repeat.insert(s[right]);
        }
        return length;

    }
};
