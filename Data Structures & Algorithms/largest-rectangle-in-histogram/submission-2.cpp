/*
Given array of integers heights where heights[i] is the ight of a bar.
Width of each bar is 1
Goal: Return the area of the largest rectangle that can be formed among the bars.

Intuition:
The brute force solution will be using a double loop
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        // Brute Force
        int maxArea{INT_MIN};
        for (int i{}; i < heights.size(); i++)
        {
            int minHeight{heights[i]};
            for (int j{i}; j < heights.size(); j++)
            {
                if (heights[j] < minHeight)
                    minHeight = heights[j];

                maxArea = std::max(maxArea, (j - i + 1) * minHeight);
            }
        }
        return maxArea;
    }
};
