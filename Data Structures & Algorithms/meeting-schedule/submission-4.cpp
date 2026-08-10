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

class Solution {
    std::vector<int> m_hoursBooked;

   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::ranges::sort(intervals, [](auto& l, auto& r) { return l.start < r.start; });

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};
