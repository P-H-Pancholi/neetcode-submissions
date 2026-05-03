class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resIdx = -1, resLen = -1;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j]){
                    if(j-i < 3 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        if((j-i+1) > resLen){
                            resIdx = i;
                            resLen = j-i+1;
                        }
                    }
                }
            }
        }
        string res = "";
        for(int i = resIdx; i < resIdx+resLen; i++){
            res += s[i];
        }
        return res;
    }
};
