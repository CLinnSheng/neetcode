class Solution {
public:
    string minWindow(string s, string t) 
    {
        if (s == t)
        {
            return s;
        }    

        int len_s(s.length()), len_t(t.length());
        if (s.length() < t.length())
        {
            return "";
        }

        // Brute force will just simply trying every single possible substring of s
        // This will cost O(n^2) and then we need to lookup the hash table that store the frequency of each character
        // encounter in s whether does it exceed t or not. This will cost another O(n)
        // O(n^3)

        // Optimized --> Remove the double loop to a single loop by using sliding window algorithm to prevent
        // overlapped substring
        // once find a valid window we we will try to shrink it
        std::unordered_map<char, int> map_s, map_t;
        int counter{len_t};
        for (const auto ch : t)
            map_t[ch]++;

        int index{}, len(INT_MAX);
        int left{}, right{};
        while (right < len_s)
        {
            map_s[s[right]]++;
            // Check whether this character appear in t or not
            if (map_t.count(s[right]) && map_t[s[right]] >= map_s[s[right]])
            {
                counter--;
            }

            // If valid window we try to shrink
            while (counter == 0 && left <= right)
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    index = left;
                }

                map_s[s[left]]--;

                if (map_t.count(s[left]) && map_t[s[left]] > map_s[s[left]])
                {
                    counter++;
                }
                left++;
            }
            right++;
        }
        return len == INT_MAX? "" : s.substr(index, len);
    }
};
