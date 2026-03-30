class Solution {
public:
    int characterReplacement(string s, int k) {
        // Substring**. Almost the same question as before but with replacement
        // So we want the longest substring, so we only replace the minority in the window

        int left{}, right{};
        int currMaxCnt{}, ans{};
        vector<int> cnt(26, 0); // Store the cnt of each characters
        while (right < s.length())
        {
            cnt[s[right] - 'A']++;
            currMaxCnt = std::max(currMaxCnt, cnt[s[right] - 'A']);

            if (right - left + 1 - currMaxCnt > k)
            {
                cnt[s[left++] - 'A']--;
            }
            ans = std::max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
