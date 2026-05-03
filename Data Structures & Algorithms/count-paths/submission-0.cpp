class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n, 0));
        dp[0][0] = 1;
        queue<pair<int,int>> q;
        set<pair<int,int>> s;
        q.push({0,0});
        s.insert({0,0});
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            int i = curr.first, j = curr.second;
            if(i+1 < m){
                dp[i+1][j] += dp[i][j];
                if(s.find({i+1, j}) == s.end()){
                    q.push({i+1, j});
                    s.insert({i+1, j});
                }
                
            }
            if(j+1 < n){
                dp[i][j+1] += dp[i][j];
                if(s.find({i, j+1}) == s.end()){
                    q.push({i, j+1});
                    s.insert({i, j+1});
                }
                
            }

        }
        return dp[m-1][n-1];
    }
};
