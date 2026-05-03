class Solution {
public:
    bool isCycle(vector<vector<int>> &graph, int node, 
        vector<int> &res, vector<bool> &recStack, vector<bool> &isVisited){
        if(recStack[node]) return true;
        if(isVisited[node]) return false;
        recStack[node] = true;
        isVisited[node] = true;
        for(int i : graph[node]){
            if(isCycle(graph, i, res, recStack, isVisited)) return true;
        }
        res.push_back(node);
        recStack[node] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>{});
        for(vector<int> v : prerequisites){
            graph[v[0]].push_back(v[1]);
        }
        vector<int> res;
        vector<bool> isVisited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!isVisited[i]){
                if(isCycle(graph, i, res, recStack, isVisited)) return {};
            }
        }
        return res;
    }
};