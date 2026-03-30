/*
Given 2 string s & t.
Goal: Return the shortest substring of s such that every character in t,
including duplicates is present in the substring.

Intuition:
The brute force will be basically checking every substring in s whether it it have
all the characters in t or not. But this will very time expensive --> O(n^3)

And also the key important thing is have every characters in t.
So the order doesnt matter just the frequenecy of character does matter.
So this lead to using hash map.

So from the brute force way, we can see checking the overlapping the substring.
THen from this we can use sliding window algorithm.
So basically we will keep extending the window until contain all character, then we start
to shrink the window until the window is not valid anymore.

While for checking whether the window is valid or not, we need to have a counter
that count every character in t. If the character currently in s is a character in t then minus
If the counter hit 0 then is a valid window
*/

class Solution {
public:
    string minWindow(string s, string t) 
    {
        // Base Case
        if (s.length() < t.length() || t.empty())
            return "";

        if (s == t)
            return s;

        unordered_map<char, int> mapT, mapS;

        for (const auto& ch : t)
            mapT[ch]++;

        int counter(t.length());
        int left{}, right{};
        int len{INT_MAX}, index{};

        while (right < s.length())
        {
            mapS[s[right]]++;

            if (mapT.count(s[right]) && mapT[s[right]] >= mapS[s[right]])
                counter--;

            while (counter == 0)
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    index = left;
                }

                mapS[s[left]]--;

                if (mapT.count(s[left]) && mapT[s[left]] > mapS[s[left]])
                    counter++;

                left++;
            }
            right++;
        }

        return len == INT_MAX? "" : s.substr(index, len);
    }
};
