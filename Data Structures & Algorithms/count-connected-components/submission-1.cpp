class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited){
        visited[node] = true;
        for(int i : graph[node]){
            if(!visited[i]) dfs(graph, i, visited);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n, vector<int>{});
        for(vector<int> v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;
                dfs(graph, i, visited);
            }
        }
        return components;
    }
};
