/*
Given array of integers heights where heights[i] is the ight of a bar.
Width of each bar is 1
Goal: Return the area of the largest rectangle that can be formed among the bars.

Intuition:
The brute force solution will be using a double loop

But how cna we optimize it? From the observation of brute force, we can tell that
we needed the information of the lowest height from both side.
So for a bar we can extend it to the right as long as the bar after that keep increasing.
So whenever we encounter a shorter bar, we need to compute the area because we no longer can extend it to the right
THen this lead to using a stack because we needed the informatoin of height of the bars we iterated
Since we mention about need increasing order, so the stack we maintiang will be in monotonic order

Time Complexity: O(N)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        // Brute Force
        // int maxArea{INT_MIN};
        // for (int i{}; i < heights.size(); i++)
        // {
        //     int minHeight{heights[i]};
        //     for (int j{i}; j < heights.size(); j++)
        //     {
        //         if (heights[j] < minHeight)
        //             minHeight = heights[j];

        //         maxArea = std::max(maxArea, (j - i + 1) * minHeight);
        //     }
        // }
        // return maxArea;

        // Need information for height and index
        std::stack<std::pair<int ,int>> bars;
        int maxArea{}, nBars(heights.size());

        for (int i{}; i < nBars; i++)
        {
            int currIndex{i};

            // Keep popping until valid extending right from the bar store in the stack
            while (!bars.empty() && bars.top().first > heights[i])
            {
                auto currBar{bars.top()};
                bars.pop();

                currIndex = currBar.second;
                maxArea = std::max(maxArea, (i - currIndex) * currBar.first);
            }  

            // the index storing will be how far can we push to the left
            bars.push({heights[i], currIndex});
        }

        while (!bars.empty())
        {
            auto top{bars.top()};
            bars.pop();

            maxArea = std::max(maxArea, (nBars - top.second) * top.first);
        }
        return maxArea;
    }
};
 