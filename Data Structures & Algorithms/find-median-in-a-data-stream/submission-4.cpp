/*
 * Median just simply refer to the middle element of the array
 * How can we easily find it?
 * Split the array into half
 * Left half -> maxHeap will get the most right element
 * Right half -> minHeap will get the most left element
 * We also need to make sure both heap is always balance which at most the diff only 1
 * */
#include <cmath>
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>
class MedianFinder
{
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;

  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Rebalance if the shape not align
        if (std::abs(int(minHeap.size() - maxHeap.size())) > 1)
        {
            if (minHeap.size() > maxHeap.size())
            {
                auto top = minHeap.top();
                minHeap.pop();

                maxHeap.push(top);
            }
            else
            {
                auto top = maxHeap.top();
                maxHeap.pop();

                minHeap.push(top);
            }
        }
    }

    double findMedian()
    {
        int size = minHeap.size() + maxHeap.size();

        if (size % 2)
        {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }

        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};
