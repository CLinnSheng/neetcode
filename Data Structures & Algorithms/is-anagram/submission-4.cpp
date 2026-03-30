class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> cnt(26, 0);
        for (const auto ch : s)
            cnt[ch - 'a']++;

        for (const auto ch : t)
            cnt[ch - 'a']--;

        for (const auto i : cnt)
            if (i != 0)
                return false;

        return true;
    }
};
