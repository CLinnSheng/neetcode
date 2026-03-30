/*
This question is a little bit similar of find whether the permutation is available in the substring or not
but the thing that is different over here is get the shortest substring such that it contain every character.
Since freq of each char matter over here --> Hash Map or Array
The condition of shrinking the window is when ever the window is valid
But need a smart way to konw whether the current window is valid or not instead of keep going through the map or array which takes O(n)
How can we make it in O(1)? --> The easiest way is keep track of the count which is the number of char we still dont have
*/
class Solution {
public:
    string minWindow(string s, string t) 
    {
        // Base Case
        if (s == t)
        {
            return s;
        }

        int len_s = s.length(), len_t = t.length();
        if (len_t > len_s)
        {
            return "";
        }

        // Need to keep track of the index & len
        int index{}, len{INT_MAX};
        int counter{len_t};
        // Hash Map to get the count of each char
        std::unordered_map<char, int> map_s, map_t;
        for (const auto ch : t)
        {
            map_t[ch]++;
        }

        int left{}, right{};

        while (right < len_s)
        {
            auto currChar = s[right];

            // Include this char into the window
            map_s[currChar]++;

            // Check whether this char is in t or not and also
            // the freq matter so we need to check the freq as well
            if (map_t.count(currChar) && map_t[currChar] >= map_s[currChar])
            {
                // Reduce the number of char we need to map
                counter--;
            }

            // Check the window
            while (counter == 0 && left <= right)
            {
                // Update len & index
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    index = left;
                }
                std::cout << (s.substr(index, len)) << '\n';

                // Remove left from the window
                map_s[s[left]]--;

                // Check wether this character exist in t or not
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
