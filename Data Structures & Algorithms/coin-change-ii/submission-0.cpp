class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Base: 0 coins available, only amount=0 has 1 way
        for (int j = 0; j <= amount; j++)
            dp[n][j] = (j == 0) ? 1 : 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                int skip = dp[i + 1][j];
                int take = (j >= coins[i]) ? dp[i][j - coins[i]] : 0;
                dp[i][j] = skip + take;
            }
        }
        return dp[0][amount];
    }
};