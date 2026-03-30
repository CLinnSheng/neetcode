/*
Rearrange the charaters of s so that any 2 adjacent characters are not the same
Goal: Return any possible rearrangement of s or return empty string

Intuition:
need to rearrange the original string such that no 2 any adjacent characters are the same.
Then in any possible rearrangement
we need to always finsih the character with the most frequent character first.

*/
class Solution {
public:
    string reorganizeString(string s) 
    {
        std::string answer{};
        std::unordered_map<char, int> freq;
        for (const auto& ch : s)
            freq[ch]++;

        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::less<>>maxHeap;
        for (const auto &[ch, cnt] : freq)
            maxHeap.emplace(cnt, ch);

        std::pair<int, char> prevChar{0, ' '};
        while (!maxHeap.empty() || prevChar.first > 0)
        {
            // no more alternative character left
            if (prevChar.first > 0 && maxHeap.empty())
                return  "";

            auto [cnt, currChar] = maxHeap.top();
            maxHeap.pop();
            
            answer += currChar;
            cnt--;

            // push it back to the heap
            if (prevChar.first > 0)
                maxHeap.emplace(prevChar.first, prevChar.second);

            prevChar = std::make_pair(cnt, currChar);
        }

        return answer;
    }
};