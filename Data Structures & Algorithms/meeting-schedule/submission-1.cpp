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
        if (intervals.size() <= 1) {
            return true;
        }

        for (const Interval& interval : intervals) {
            if(m_hoursBooked.size() < interval.end) {
                m_hoursBooked.resize(interval.end, -1);
            }

            for(int i = interval.start; i < interval.end; i++) {
                if(m_hoursBooked[i] == -1)
                    m_hoursBooked[i] = 0;
                else
                    return false;
            }
                
        }

        return true;
    }
};
