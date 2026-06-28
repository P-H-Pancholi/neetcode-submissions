class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(vector<int> v : intervals){
            end = max(end, v[1]);
        }
        vector<int> sz_map(end-start+1, INT_MAX);
        for(vector<int> v : intervals){
            int curr = v[1]-v[0]+1;
            for(int i = v[0]; i <= v[1]; i++){
                sz_map[i-start] = min(sz_map[i-start], curr);
            }
        }
        vector<int> res;
        for(int i : queries){
            if(i-start >= sz_map.size()){
                res.push_back(-1);
            }else{
                if(sz_map[i-start] == INT_MAX){
                    res.push_back(-1);
                }else{
                    res.push_back(sz_map[i-start]);
                }
            }
        }
        return res;
    }
};
