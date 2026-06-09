class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m+n != s3.size()) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        for(int i = m-1; i >= 0; i--){
            if(s1[i] == s3[i+n]){
                dp[i][n] = dp[i+1][n];
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(s2[i] == s3[i+m]){
                dp[m][i] = dp[m][i+1];
            }
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s1[i] == s3[i+j] && dp[i+1][j]){
                    dp[i][j] = true;
                }
                if(s2[j] == s3[i+j] && dp[i][j+1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};
