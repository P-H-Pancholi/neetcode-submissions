class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            return  a[0] < b[0]? true : (a[0] == b[0]) ?  a[1] < b[1] : false;
        });
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size()){
            if(i == intervals.size()-1){
                res.push_back(intervals[i]);
                i++;
                continue;
            }
            if(intervals[i][1] >= intervals[i+1][0]){
                int newStart = intervals[i][0];
                int newEnd = max(intervals[i][1], intervals[i+1][1]);
                int j = i+1;
                while(j < intervals.size() && intervals[j][0] <= newEnd){
                    newEnd = max(newEnd, intervals[j][1]);
                    j++;
                }
                res.push_back({newStart, newEnd});
                i = j;
            }else{
                res.push_back(intervals[i]);
                i++;
            }
        }
        return res;
    }
};
