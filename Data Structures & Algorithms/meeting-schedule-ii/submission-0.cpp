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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            if(a.start == b.start){
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        vector<Interval> rooms;
        for(Interval curr : intervals){
            int i = 0;
            while(i < rooms.size()){
                if(rooms[i].end <= curr.start){
                    // it can be in the same room
                    rooms[i] = curr;
                    break;
                }
                i++;
            }
            if(i == rooms.size()){
                rooms.push_back(curr);
            }
        }
        return rooms.size();
    }
};
