#include <deque>
#include <string>
#include <vector>

/*
 * Goal: Derive the order of letters in this language, if order is invalid
return empty string and if there are multiple of them return any
 *
 *
 * string a is lexicographically smaller than a string b if either of the
following is true: The first letter where they differ is smaller in a than in b.
    There is no index i such that a[i] != b[i] and a.length < b.length.
 *
 * Intuition: This is actually a graph problem as one character will point to
the next character and we also can observe
 * this is a topological sort graph, as a character must comes after another
character Detect if there is any contradiction in the ordering rules, such as a
cycle in the graph which would make it impossible to determine the order, or an
improper ordering like a word being a prefix of a previous word but appearing
later in the list. Assuming the ordering rules do not contain contradictions,
perform a topological sort on the graph to find the alien language character
order. If we can complete the topological sort with all characters accounted
for, we have successfully identified a possible alien language order. Otherwise,
we return an empty string.
 * */
class Solution {
public:
  std::string foreignDictionary(std::vector<std::string> &words) {

    // graph
    std::vector<std::vector<bool>> graph(26, std::vector<bool>(26, false));
    std::vector<bool> visited(26, false);

    // character seen so for
    int numCharacters{};
    int wordCount(words.size());

    // Building the graph
    for (int i{}; i < wordCount - 1; i++) {
      for (const char &ch : words[i]) {
        int charIndex = ch - 'a';
        if (!visited[charIndex]) {
          numCharacters++;
          visited[charIndex] = true;
          // if no more characters left in the dict straight away quit
          if (numCharacters == 26)
            break;
        }
      }

      int wordLength = words[i].length();

      for (int j{}; j < wordLength; j++) {
        // if both the prefixes are the same but the next word is shorter than
        // the current word then it is error
        if (j >= words[i + 1].size())
          return "";

        char currentWordChar{words[i][j]}, nextWordChar{words[i + 1][j]};
        if (currentWordChar == nextWordChar)
          continue;

        // invalid ordering, since the array of word is sorted lexicographically
        // so by right currentWordChar come before nextWordChar
        if (graph[nextWordChar - 'a'][currentWordChar - 'a'])
          return "";

        // found the order then move on to the next word
        graph[currentWordChar - 'a'][nextWordChar - 'a'] = true;
        break;
      }
    }

    // Register the last words, since we not doing it in the for loop
    for (const char &ch : words[wordCount - 1]) {
      int charIndex = ch - 'a';
      if (!visited[charIndex]) {
        numCharacters++;
        visited[charIndex] = true;

        if (numCharacters == 26)
          break;
      }
    }

    std::vector<int> inDegree(26, 0);
    // have an array of indegree to keep track of how many nodes is pointing to
    // the nodes
    for (int i{}; i < 26; i++)
      for (int j{}; j < 26; j++)
        if (visited[i] && visited[j] && graph[i][j])
          inDegree[j]++;

    // BFS to perform topological sort, but we need to prepopulate the deque
    // with all those nodes with 0 inDegree, so we can start from this node to
    // traverse
    std::deque<int> queue;
    for (int i{}; i < 26; i++)
      if (!inDegree[i] && visited[i])
        queue.emplace_back(i);

    std::string ans;
    while (!queue.empty()) {
      int currentChar = queue.front();
      queue.pop_front();

      ans += currentChar + 'a';
      for (int i{}; i < 26; i++)
        if (i != currentChar && visited[i] && graph[currentChar][i])
          if (--inDegree[i] == 0)
            queue.emplace_back(i);
    }

    // if the dictionary size is less than the number of unique characters found
    // then it must exists a cycle
    if (ans.size() < numCharacters)
      return "";

    return ans;
  }
};
