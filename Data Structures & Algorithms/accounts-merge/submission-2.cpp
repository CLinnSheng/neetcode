#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector, std::string;

/*
 * Key insight: names are NOT reliable identifiers — two different people can
 * share the same name. The only reliable signal that two accounts belong to
 * the same person is a SHARED EMAIL. If any email appears in two different
 * account rows, those rows must belong to the same person and should be merged.
 *
 * Approach: Union-Find, where each NODE is an account (row index in
 * `accounts`), not an email. As we scan through each account's emails, we keep
 * a map (emailIndex: email -> row index) recording which row we FIRST saw a
 * given email in.
 *
 *   - If we see an email for the first time, record its owning row in
 * emailIndex.
 *   - If we see an email we've already recorded, that means the CURRENT row and
 *     the row that first claimed this email belong to the same person -> union
 *     the two row indices together.
 *
 * After processing all accounts, every row belongs to some root row (its
 * representative person). We then do a second pass over all accounts, find
 * each row's root, and bucket all of that row's emails under its root. Each
 * bucket becomes one merged person: sort the emails, and label the group with
 * the name from the root row (any row in the group would give the same name
 * per the problem's guarantee, since merged accounts share one person).
 */
class UnionFind {
private:
  vector<int> parents, ranks;

public:
  UnionFind(int n) {
    parents.resize(n);
    for (int i{}; i < n; i++) {
      parents[i] = i;
    }

    ranks.resize(n, 1);
  }

  int findParent(int x) {
    if (x != parents[x]) {
      parents[x] = findParent(parents[parents[x]]);
    }

    return parents[x];
  }

  void join(int node1, int node2) {
    int parent1 = this->findParent(node1);
    int parent2 = this->findParent(node2);

    if (parent1 == parent2) {
      return;
    }

    if (ranks[parent1] > ranks[parent2]) {
      parents[parent2] = parent1;
      ranks[parent1] += ranks[parent2];
    } else {
      parents[parent1] = parent2;
      ranks[parent2] += ranks[parent1];
    }
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n(accounts.size());
    UnionFind uf = UnionFind(n);

    // Track all the emails index from `accounts`, so we can easily know which
    // person does this email belongs to
    std::unordered_map<string, int> emailIndex;

    // Merged all the accounts that belong to the same person
    for (int i{}; i < n; i++) {
      auto name = accounts[i][0];

      for (int j{1}; j < accounts[i].size(); j++) {
        auto &email = accounts[i][j];

        if (emailIndex.find(email) != emailIndex.end()) {
          // If encounter the same email, then merge the accounts because is
          // belong to the same person
          uf.join(i, emailIndex[email]);
        } else {
          emailIndex[email] = i;
        }
      }
    }

    // Group email by name
    std::unordered_map<int, vector<string>> emailGroup;
    for (const auto &[email, index] : emailIndex) {
      int parent = uf.findParent(index);
      emailGroup[parent].emplace_back(email);
    }

    vector<vector<string>> answer;
    for (auto &[index, emails] : emailGroup) {
      std::sort(emails.begin(), emails.end());
      vector<string> subStr;

      subStr.emplace_back(accounts[index][0]);
      subStr.insert(subStr.end(), emails.begin(), emails.end());

      answer.emplace_back(subStr);
    }

    return answer;
  }
};
