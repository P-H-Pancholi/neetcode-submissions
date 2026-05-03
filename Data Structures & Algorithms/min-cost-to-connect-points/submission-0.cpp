class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> graph(points.size());
        for(int i = 0; i < points.size(); i++){
            int j = i+1;
            while(j < points.size()){
                int manDist = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                graph[i].push_back({j, manDist});
                graph[j].push_back({i, manDist});
                j++;
            }
        }
        int res = 0;
        set<int> st;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(st.size() < points.size()){
            pair<int,int> curr = pq.top();
            pq.pop();
            if(st.find(curr.second) != st.end()) continue;
            st.insert(curr.second);
            res += curr.first;
            for(pair<int,int> p : graph[curr.second]){
                if(st.find(p.first) == st.end()){
                    pq.push({p.second, p.first});
                }
            }
        }
        return res;
    }
};
