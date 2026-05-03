class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i = n-1; i >= 0; i--){
            for(string word : wordDict){
                if(word.size() > n-i) continue;
                int j = 0;
                while(j < word.size()){
                    if(s[i+j] != word[j]) break;
                    j++;
                }
                if(j == word.size() && dp[i+j]) {
                    dp[i] = true;
                    break;
                }
                
            }
        }
        return dp[0];
    }
};