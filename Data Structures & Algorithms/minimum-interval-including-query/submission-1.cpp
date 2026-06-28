class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());
        int idx = 0;
        unordered_map<int,int> umap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < sorted_queries.size(); i++){
            while(idx < intervals.size() && intervals[idx][0] <= sorted_queries[i]){
                pq.push({(intervals[idx][1]-intervals[idx][0]+1), intervals[idx][1]});
                idx++;
            }
            while(!pq.empty() && pq.top().second < sorted_queries[i]){
                pq.pop();
            }
            if(pq.empty()){
                umap[sorted_queries[i]] = -1;    
            }else{
                umap[sorted_queries[i]] = pq.top().first;
            }
        }
        vector<int> res(queries.size(), -1);
        for(int i = 0; i < queries.size(); i++){
            if(umap.find(queries[i]) != umap.end()){
                res[i] = umap[queries[i]];
            }
        }
        return res;
    }
};
