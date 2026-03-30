/*
Sliding window of size k moving from left to right.
Can only see k numbers in the window.
Goal: Return the max sliding window.

Intuition:
The brute force will be checking the maximum elment everytime we move the window.
But this will be O(n^2), how can we optimize it to O(n)?
The place we need to work on will be checking the maximum element.
Is there any better way to get the maximum element in O(1)

Another way of getting the maximum element which is by using a maxHeap,
we can get it in O(1) but pushing into the heap will be O(lgn)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        std::priority_queue<std::pair<int, int>> maxHeap;
        std::vector<int> ans;

        for (int right{}; right < nums.size(); right++)
        {
            maxHeap.push({nums[right], right});

            // When reach the sliding window of size 'k'
            if (right + 1 >= k)
            {
                // Handle when the maximum element is out of the window
                while (maxHeap.top().second <= right - k)
                    maxHeap.pop();

                ans.emplace_back(maxHeap.top().first);
            }
        }
        return ans;
    }
};
