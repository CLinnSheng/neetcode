/*
Intuition: Use a stack because of the first in last out characteristics
keep storing until no more left parentheses after that keep checking from the top
we only check for the right parentheses
*/
class Solution {
public:
    bool isValid(string s) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        deque<char> stack;
        unordered_map<char, char> p = {{')', '('}, {'}', '{'}, {']', '['}};

        for (const auto &c : s) 
            if (p.count(c)) {
                if (stack.empty())  return false;
                if (stack.back() != p[c])   return false;
                stack.pop_back();
            }
            else
                stack.emplace_back(c);
        

        return stack.empty();
    }
};
