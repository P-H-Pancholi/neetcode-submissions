class Solution {
public:
    bool isCycle(vector<vector<int>> &graph, int node, vector<bool> &visited, 
    int parent, int &visNode){
        visited[node] = true;
        visNode++;
        
        for(int i : graph[node]){
            if(!visited[i]){
                if(isCycle(graph, i, visited, node, visNode)) return true;
            } else if(i != parent) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n, vector<int>{});
        for(vector<int> v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int visNode = 0;
        if (isCycle(graph, 0, visited, -1, visNode)) return false;
        return visNode == n;
    }
};