class Solution {
public:
    bool isPalindrome(string s) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int start = 0, end = s.size() - 1;

        while (start < end)
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            else if (tolower(s[start++]) != tolower(s[end--]))    return false;
        

        return true;
    }
};
