class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            int j = 1;
            while(i+j < n && j <= nums[i]){
                if(dp[i+j] != INT_MAX) dp[i] = min(dp[i], 1+dp[i+j]);
                j++;
            }
        }
        return dp[0];
    }
};
