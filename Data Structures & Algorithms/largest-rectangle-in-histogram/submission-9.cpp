class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Area = Wdith * Height
        // To determine the height of at indices i we need to know how much we can expand to the left and to the right
        // So this will take O(n^2)
        // Is there a way to optimize this to O(n) or (nlgn)?
        // Since order matter we cant sort it, so the possible way is O(n)
        // How we can optimize the finding of the furthest we can expand?
        // So in order to keep expanding to the right, the rectangle has to keep getting taller
        // So we can keep a monotomic increasing stack, so for each value in stack we need to find the left and right boundary

        std::deque<int> m_stack;
        int maxArea{};
        int n = heights.size();

        for (int i{}; i < n; i++)
        {
            // Check whether can we still expand to the right
            while (!m_stack.empty() && heights[m_stack.back()] > heights[i])
            {
                int index = m_stack.back();
                m_stack.pop_back();

                int width = i - (!m_stack.empty()? m_stack.back() + 1 : 0);
                maxArea = std::max(maxArea, width * heights[index]);
            }

            m_stack.push_back(i);
        }

        // Take Account of Keep Increasing stack
        while (!m_stack.empty())
        {
            int index = m_stack.back();
            m_stack.pop_back();

            int width = n - (!m_stack.empty()? m_stack.back() + 1 : 0);
            maxArea = std::max(maxArea, width * heights[index]);
        }

        return maxArea;
    }
};
