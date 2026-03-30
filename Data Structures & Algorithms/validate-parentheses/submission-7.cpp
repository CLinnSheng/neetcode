class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        std::deque<char> stack;
        for (const auto ch : s)
        {
            if (!mp.count(ch))
            {
                stack.push_back(ch);
                continue;
            }

            if (stack.empty() || stack.back() != mp[ch])
            {
                return false;
            }

            stack.pop_back();
        }
        return stack.empty();
    }
};