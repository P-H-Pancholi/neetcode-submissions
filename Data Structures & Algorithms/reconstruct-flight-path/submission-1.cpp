class Solution {
public:
    bool dfs(string& curr, unordered_map<string, vector<string>>& adjList, vector<string> &res, int tickets){
        if(res.size() == tickets) return true;
        if(adjList[curr].size() == 0) return false;
        for(int i = 0; i < adjList[curr].size(); i++){
            string currStr = adjList[curr][i];
            adjList[curr].erase(adjList[curr].begin()+i);
            res.push_back(currStr);
            if(dfs(currStr, adjList, res, tickets)) return true;
            res.pop_back();
            adjList[curr].insert(adjList[curr].begin()+i, currStr);
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        unordered_map<string, vector<string>> adjList;
        for(vector<string> v : tickets){
            adjList[v[0]].push_back(v[1]);
        }
        vector<string> res = {"JFK"};
        string start = "JFK";
        dfs(start, adjList, res, tickets.size()+1);
        return res;
    }
};
