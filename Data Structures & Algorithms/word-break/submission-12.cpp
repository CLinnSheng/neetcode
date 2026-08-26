class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // So every at index, we can try to parse it and see whether is in part of the word in wordDict or not
        // Observation from recursive, we repeating some work in some subproblem
        // Which is checking from this index onwards is it valid to break it
        // Thus we can cache it
        std::unordered_map<int, bool> cache;
        return recursive(s, wordDict, 0, cache);
    }

    bool recursive(std::string& s, const std::vector<string>& wordDict, int index, std::unordered_map<int, bool>& cache)
    {
        // Base Case
        if (index == s.length())
        {
            return true;
        }

        if (cache.find(index) != cache.end())
        {
            return cache[index];
        }

        // Trying every single word
        for (const auto word : wordDict)
        {
            int len = word.length();

            // Check whether does the current index can form any word from wordDict
            if (index + len <= s.length() && s.substr(index, len) == word)
            {
                if (recursive(s, wordDict, index + len, cache))
                {
                    cache[index] = true;
                    return true;
                }
            }
        }


        cache[index] = false;
        return false;

    }
};
