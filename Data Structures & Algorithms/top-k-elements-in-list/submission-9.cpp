#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Goal: Return the k most frequent elements
 *
 * Intuition:
 * Important things is "k most frequent". We can use a priority queue and the queue is based on the number of element
 * for each integer. Time Complexity: O(nlgn)
 * */
struct Comparator
{
    bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B)
    {
        return A.second < B.second;
    }
};
class Solution
{
  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        // collect the freq of each char
        std::unordered_map<int, int> freq;
        for (const auto num : nums)
        {
            freq[num]++;
        }

        // Most direct way is straight away use a max heap
        // Push it into the heap
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> maxHeap;
        for (const auto &[num, cnt]: freq)
        {
            maxHeap.push(std::make_pair(num, cnt));
        }

        std::vector<int> ans;
        while (k)
        {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
            k--;
        }
        
        return ans;
    }
};
