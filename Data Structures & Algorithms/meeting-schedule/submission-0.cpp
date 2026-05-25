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
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if(a.start == b.start){
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        for(int i = 1; i < intervals.size(); i++){
            Interval curr = intervals[i];
            Interval prev = intervals[i-1];
            if(prev.end > curr.start){
                return false;
            }
        }
        return true;
    }
};
