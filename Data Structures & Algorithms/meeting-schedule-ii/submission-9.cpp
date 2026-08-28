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
Finding the minimum number of rooms required to schedule all meeting
In other way is like finding the number of conflicted events

We can visualize the meetings as line segment on a number line
So basically we will iterate through the time line, and everytime if an meeting start we increment the room usage and decrement it when an meeting end.
So at every single point of time keep track of the room usage
*/
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 1)
        {
            return 1;
        }

        // Use map can easily handle at that particular timestamp where a meeting start and end
        std::map<int, int> time_line;

        for (const auto& interval : intervals)
        {
            time_line[interval.start]++; // Starting time
            time_line[interval.end]--; // Ending time
        }

        int cnt{};
        int rooms{};

        // Iterate through the time line
        for (const auto &[time, action] : time_line)
        {
           cnt += action; 
           rooms = std::max(rooms, cnt);
        }

        return rooms;
    }
};
