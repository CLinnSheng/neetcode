class Solution {
public:
// Intuition: Find the longest repeating substring with k times replacement
// Direction: Iterate through the array and update the number of count of each character
// while right keep increasing and we also keep tracking the maxcount
// right - left + 1 - maxcount <= k is valid
    int characterReplacement(string s, int k) {
       
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int left = 0, right = 0;
        int size = s.size(), cnt = 0;
        int length = INT_MIN;

        if (!size)  return 0;
        
        vector<int> count(26);

        for (; right < size; right++){
            count[s[right] - 'A']++;
            // If meet differenct character, we will swap the character while the cnt still remain the same
            // we can know the number of character we swap by length - cnt
            cnt = max(cnt, count[s[right] - 'A']);

// exceed the number of swap
            if (right - left + 1 - cnt > k)
                // shift we sliding window
                count[s[left++] - 'A']--;

            length = max(right - left + 1, length);

        }

        return length;

    }
};
