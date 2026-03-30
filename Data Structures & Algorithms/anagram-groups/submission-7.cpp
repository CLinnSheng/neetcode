// Anagrams string with the same frequency for each character
// 1. Can have a hash map with string as the key then value will be the list of strings with the same frequency for each character
// way to determine can just simply sort it to see whether is it an anagram or not
// Time Complexity will be O(m * nlgn)
// 2. To optimze it we can do on the sorting part, so instead of sorting the word to form the key we can just
// simply create our own key which is the key element of anagram the frequency of each char
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Approach 1
        // std::unordered_map<std::string, std::vector<std::string>> mp;
        
        // for (const auto& str: strs)
        // {
        //     std::string temp = str;
        //     std::sort(temp.begin(), temp.end());
        //     mp[temp].push_back(str);
        // }

        // std::vector<std::vector<std::string>> answer;
        // for (const auto &[_, strs] : mp)
        // {
        //     answer.push_back(strs);
        // }
        // return answer;

        // Approach 2
        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (const auto& str : strs)
        {
            // Building the key
            std::vector<int> freq(26, 0);
            std::string key{};

            for (const char ch : str)
                freq[ch - 'a']++;

            for (const auto i : freq)
                key += "#" + std::to_string(i);

            mp[key].push_back(str);
        }

        std::vector<std::vector<std::string>> answer;
        for (const auto& [_, strs] : mp)
        {
            std::cout << "KEY: " << _ << '\n';
            answer.push_back(strs);
        }
        return answer;
    }
};
