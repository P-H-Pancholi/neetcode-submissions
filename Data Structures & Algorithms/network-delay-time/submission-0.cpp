class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(vector<int> v : times){
            graph[v[0]].push_back({v[1], v[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> isVisited(n+1, false);
        pq.push({0, k});
        int res = INT_MIN;
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();
            if(isVisited[curr.second]) continue;
            isVisited[curr.second] = true;
            int currDistance = curr.first;
            res = max(res, currDistance);
            for(pair<int,int> p : graph[curr.second]){
                cout << p.first << endl;
                if(!isVisited[p.first]){
                    pq.push({currDistance+p.second, p.first});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(!isVisited[i]){
                return -1;
            }
        }
        return res;
    }
};
