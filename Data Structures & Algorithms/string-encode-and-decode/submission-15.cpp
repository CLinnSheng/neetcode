#include <string>
#include <vector>
using std::vector, std::string;
/*
 * Encode and decode the string
 * strs[i] contains any possible characters out of 256 valid ASCII characters.
 * So numbers and special character is included, then we need to find a way to determine is end of the string
 * so im thinking of special character + length at end of each word.
 * So we just need to find the first special character lets say star from 0 and then check whether is it the next word
 * is a character
 * Actually instead of putting at the back, putting at the front is more easily to check so length  + '#'. So we dont
 * have to handle about is it conisder part of the string or not
 * */
class Solution
{
  public:
    string encode(vector<string> &strs)
    {
        string encode_str{};

        for (const auto &str : strs)
        {
            encode_str += std::to_string(str.length()) + "#" + str;
        }

        return encode_str;
    }

    vector<string> decode(string s)
    {
        // Steps
        // First find the length which is until '#'
        // Then extract teh string with the length that we got
        int index{};
        vector<string> ans;

        while (index != s.length())
        {
            // Find the index of the first '#'
            int special_index = s.find('#', index);
            int len = stoi(s.substr(index, special_index - index));

            // Move the special index by 1, which means the index of the first character
            special_index++;
            string str = s.substr(special_index, len);

            ans.push_back(str);

            index = special_index + len;
        }

        return ans;
    }
};
