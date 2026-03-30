/*
We can at most delete one character,
so what shall we do when found a mismatch?
try either removing the left or the right
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int length = s.length();
        int left{}, right{length - 1};

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return helper(s.substr(0, left) + s.substr(left + 1)) ||
                        helper(s.substr(0, right) + s.substr(right + 1));
            }

            left++;
            right--;
        }
        return true;
    }

    bool helper(std::string str)
    {
        int size = str.length();
        int left{}, right{size - 1};

        while (left < right)
        {
            if (str[left] != str[right])
            {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};