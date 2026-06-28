class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int j = 0;
        while(j < intervals.size()){
            // if the interval is non-overlapping
            if(newInterval[0] < intervals[j][0] && newInterval[1] < intervals[j][0]){
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin()+j, intervals.end());
                return res;
            }
            if(newInterval[0] > intervals[j][0] && newInterval[0] > intervals[j][1]){
                res.push_back(intervals[j]);
                j++;
                continue;
            }
            int new_start = min(intervals[j][0], newInterval[0]);
            int new_end = newInterval[1];
            while(j < intervals.size() && newInterval[1] >= intervals[j][0]){
                new_end = max(intervals[j][1], new_end);
                j++;
            }
            res.push_back({new_start, new_end});
            res.insert(res.end(), intervals.begin()+j, intervals.end());
            return res;
        }
        res.push_back(newInterval);
        return res;
    }
};
