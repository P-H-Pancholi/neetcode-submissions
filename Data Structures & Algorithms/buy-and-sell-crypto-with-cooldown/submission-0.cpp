class Solution {
public:
    unordered_map<string, int> dp;
    int dfs(int i, bool buying, vector<int> &prices){
        if(i >= prices.size()) return 0;
        string curr_key = to_string(i) + to_string(buying);
        if(dp.find(curr_key) != dp.end()) return dp[curr_key];
        
        if(buying){
            int buy = dfs(i+1, false, prices) - prices[i];
            int cooldown = dfs(i+1, true, prices);
            dp[curr_key] = max(buy, cooldown);
        }else{
            int sell = dfs(i+2, true, prices) + prices[i];
            int cooldown = dfs(i+1, false, prices);
            dp[curr_key] =  max(sell, cooldown);
        }
        return dp[curr_key];
    }
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }
};
