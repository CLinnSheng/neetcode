#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>

struct Comparator {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.first > b.first;
    }
};
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;

        for (const auto& num : nums)
            freq[num]++;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,  Comparator> minHeap;
        for (const auto &[val, cnt] : freq)
        {
            minHeap.emplace(std::make_pair(cnt, val));
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        std::vector<int> answer;
        while (!minHeap.empty())
        {
            answer.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return answer;
    }
};
