/*
Intuition: Every single node represent a character
for example a -> p -> p -> l -> e
if we got a new word that is substr of another, we just fork out from the substr

Space Complexity: O(m*n) basically just the number of characters from all the
words
*/
#include <array>
#include <memory>
#include <string>

struct TrieNodes {
  std::array<std::shared_ptr<TrieNodes>, 26> alphabets;
  bool isWord;

  TrieNodes() : isWord{false} {
    std::fill(alphabets.begin(), alphabets.end(), nullptr);
  }
};

class PrefixTree {
private:
  std::shared_ptr<TrieNodes> root;

public:
    PrefixTree() {
        root = std::make_shared<TrieNodes>();
    }
    
  void insert(std::string word) {
    auto temp = root;

    for (const auto &c : word) {
      auto alpha_num = c - 'a';
      if (temp->alphabets[alpha_num] == nullptr)
        temp->alphabets[alpha_num] = std::make_shared<TrieNodes>();
      temp = temp->alphabets[alpha_num];
    }
    temp->isWord = true;
  }

  // Time Complexity: O(n)
  bool search(std::string word) {
    auto temp = root;

    for (const auto &c : word) {
      auto alpha_num = c - 'a';
      if (temp->alphabets[alpha_num] == nullptr)
        return false;
      temp = temp->alphabets[alpha_num];
    }
    return temp->isWord;
  }

  // Time Complexity: O(n)
  bool startsWith(std::string prefix) {
    auto temp = root;

    for (const auto &c : prefix) {
      auto alpha_num = c - 'a';
      if (temp->alphabets[alpha_num] == nullptr)
        return false;
      temp = temp->alphabets[alpha_num];
    }
    return true;
  }
};
