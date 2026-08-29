#include <algorithm>
#include <stack>
#include <vector>
using std::vector;
/*
 * Rectangle is wdith * height
 * So we can find the left most and right most we can expand taking the current index as the height
 * This will take O(n^2)
 * How can we do it in a single loop.
 * We can use a monotomic stack that store increasing height stack. So this is how it works.
 * We will keep pushing the rectangle index into the stack until we reach a bar lower than the top.
 * Which means the bar at top of the stack has reach its right wall. We can compute its area by just simply take its
 * height * 1 since the stack is monotomic increasing and the left edge will jsut simply be the last bar before it on
 * the stack One important thing is we not simply storing the index, but that index tell us from this index to the left
 * whats the min Height.
 * Leyman term: The stack simply store how far can we extend to the left by storing the min Height
 *
 * */
class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea{};
        std::stack<std::pair<int, int>> stack;

        for (int i{}; i < heights.size(); i++)
        {
            int start = i;

            // Reach the right boundary
            // Expand to the left
            while (!stack.empty() && stack.top().second > heights[i])
            {
                int height = stack.top().second;
                int index = stack.top().first;
                stack.pop();

                maxArea = std::max(maxArea, height * (i - index));
                start = index;
            }

            stack.push({start, heights[i]});
        }

        // Reach the right boundary
        // Expand to the left
        while (!stack.empty())
        {
            int height = stack.top().second;
            int index = stack.top().first;
            stack.pop();

            maxArea = std::max(maxArea, height * ((int)heights.size() - index));
        }
        return maxArea;
    }
};
