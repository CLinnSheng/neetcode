#include <string>
#include <vector>
using namespace std;
class Solution {
public:

    // Encode with the number of character for each word and end with a special character
    string encode(vector<string>& strs) {
        std::string encode{};

        for (const auto& str : strs)
        {
            encode += to_string(str.length()) + "#" + str;
        }
        return encode;
    }

    vector<string> decode(string s) {
        std::vector<string> answer;
        int ptr{};

        while (ptr < s.length())
        {
            int j = ptr;
            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(ptr, j - ptr));
            ptr = j + 1; // j = #
            answer.push_back(s.substr(ptr, len));
            ptr += len;
        }

        return answer;
    }
};
