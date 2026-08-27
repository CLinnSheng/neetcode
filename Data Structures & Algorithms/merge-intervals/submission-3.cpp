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

        std::vector<std::vector<int>> ans;
        for (int i{}; i < n; i++)
        {
            if (ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1] = std::max(ans.back()[1], intervals[i][1]);
            }

        }
        
        return ans;
    }
};
