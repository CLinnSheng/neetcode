/*
Goal: Find the kth largest element without sorting
Intuition:
How can we easily access the kth largest element? use a max heap
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
        for (const auto& num : nums)
            maxHeap.emplace(num);

        while (k - 1)
        {
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();
    }
};
