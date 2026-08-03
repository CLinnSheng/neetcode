class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Edge Case
        // same word
        if (beginWord == endWord)
        {
            return 0;
        }

        // Not able to transform because not in wordlist
        if (!std::ranges::contains(wordList, endWord))
        {
            return 0;
        }
        
        // Building the graph
        std::unordered_map<std::string, std::vector<std::string>> adjList;
        std::vector<std::string> allWords(wordList.begin(), wordList.end());
        allWords.push_back(beginWord);

        for (const auto& word : allWords)
        {
            std::string temp_word = word;

            for (int i{}; i < word.length(); i++)
            {
                char original = temp_word[i];
                temp_word[i] = '*';
                adjList[temp_word].push_back(word);
                temp_word[i] = original;
            }
        }

        std::deque<std::pair<std::string, int>> q;
        std::unordered_set<std::string> visited;

        q.push_back({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty())
        {
            auto top = q.front();
            q.pop_front();

            std::string currWord = top.first;
            int count = top.second;    

            if (currWord == endWord)
            {
                return count;
            }


            // Masking through each char to find its possible neighbor
            for (int i{}; i < currWord.length(); i++)
            {
                char original = currWord[i];
                currWord[i] = '*';

                // Push all the neighbors into the queue
                for (const auto neigh : adjList[currWord])
                {
                    if (!visited.contains(neigh))
                    {
                        visited.insert(neigh);
                        q.push_back({neigh, count + 1});
                    }
                }

                currWord[i] = original;
            }
        }

        return 0;
    }
};
