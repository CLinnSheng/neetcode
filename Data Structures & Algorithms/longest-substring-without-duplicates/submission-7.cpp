class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set_;
        int left{}, right{};
        int len{};

        while (right < s.length())
        {
            while (set_.count(s[right]) && left < right)
            {
                set_.erase(s[left]);
                left++;
            }
            set_.insert(s[right]);
            len = std::max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
