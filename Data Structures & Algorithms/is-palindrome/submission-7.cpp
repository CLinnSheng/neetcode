#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left{}, right(s.length() - 1);

        while (left < right)
        {
            while (!isalnum(s[left]))
                left++;
            while (!isalnum(s[right]))
                right--;

            if (left > right)
                break;

            if (toupper(s[left]) != toupper(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};
