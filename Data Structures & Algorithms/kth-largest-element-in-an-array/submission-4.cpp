#include <functional>
#include <queue>
#include <vector>
using std::vector;
/*
 * Finding the kth alrgest element. *Kth* --> heap
 * */
class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        std::priority_queue<int, vector<int>, std::less<>> maxHeap(nums.begin(), nums.end());
        while (k - 1)
        {
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();
    }
};
