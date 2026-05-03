class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size());
        dp[0] = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0' && (s[i-1] == '0' || s[i-1] > '2')) return 0;
            if(s[i] == '0' || s[i-1] == '0' || ((i != s.size()-1) && s[i+1] == '0') || s[i-1] > '2' || 
            (s[i-1] == '2' && s[i] > '6' )) dp[i] = dp[i-1];
            else{
                if(i == 1) dp[i] = 2;
                else dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp.back();
    }
};
