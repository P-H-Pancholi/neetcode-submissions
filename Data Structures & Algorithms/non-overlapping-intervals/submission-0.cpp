class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            return  a[0] < b[0]? true : (a[0] == b[0]) ?  a[1] < b[1] : false;
        });
        vector<int> prev = intervals[0];
        int res = 0;
        for(int i = 1; i < intervals.size(); i++){
            vector<int> curr = intervals[i];
            if(prev[1] <= curr[0]){
                // non-overlapping
                prev = curr;
            }else{
                if(prev[1] > curr[1]){
                    prev = curr;
                }
                res++;
            }
        }
        return res;
    }
};
