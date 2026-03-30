class Solution {
public:
    bool isValid(string s) {
        std::deque<char> st;
        std::unordered_map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        for (const auto ch : s)
        {
            if (!st.empty() && mp.count(ch))
            {
                if (st.back() != mp[ch])
                {
                    return false;
                }
                st.pop_back();
            }
            else
            {
                st.push_back(ch);
            }
        }
        return st.empty();
    }
};