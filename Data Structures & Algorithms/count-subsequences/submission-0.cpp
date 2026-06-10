class Solution {
public:
    int dfs(string &s, string &t, vector<vector<int>> &cache, int i, int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(cache[i][j] != -1){
            return cache[i][j];
        }
        int curr = 0;
        if(s[i] == t[j]){
            curr += dfs(s,t,cache,i+1,j+1);
        }
        curr += dfs(s,t,cache,i+1,j);
        cache[i][j] = curr;
        return curr;
    }
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(s,t,cache,0,0);
    }
};
