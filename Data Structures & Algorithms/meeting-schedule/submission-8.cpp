/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/*
Find is there any conlficts between the interval
Sort it first make everything easier afterwards
*/
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& A, const Interval& B){
           return A.start < B.start; 
        });

        for (int i{1}; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end)
            {
                return false;
            }
        }

        return true;
    }
};
