/*
Need to merge the overlapping intervals
To make thing easier, we need to sort it first, instead of keep trying one another
After sorting we can just simply compare the end of first element with the start of the next element
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end());

        std::deque<std::vector<int>> ans;
        for (int i{}; i < n; i++)
        {
            if (ans.empty())
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                // Keep merging it until cannot
                while (!ans.empty())
                {
                    // First check whether is there overlapping or not
                    auto lastEvent = ans.back();

                    // Overlap
                    if (lastEvent[1] >= intervals[i][0])
                    {
                        intervals[i][0] = std::min(lastEvent[0], intervals[i][0]);
                        intervals[i][1] = std::max(lastEvent[1], intervals[i][1]);
                        ans.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }

                ans.push_back(intervals[i]);
            }

        }
        
        return {ans.begin(), ans.end()};
    }
};
