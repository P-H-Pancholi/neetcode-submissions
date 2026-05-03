class Solution {
public:
    bool isCycle(vector<vector<int>> &graph, int node, vector<bool> &recStack, 
        vector<bool>& isVisited){
        if(recStack[node]) return true;
        recStack[node] = true;
        for(int i = 0; i < graph[node].size(); i++){
            if (isCycle(graph, graph[node][i], recStack, isVisited)) return true;
        }
        recStack[node] = false;
        isVisited[node] = true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>{});
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> isVisited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!isVisited[i]){
                if(isCycle(graph, i, recStack, isVisited)) return false;
            }
        }
        return true;
    }
};
