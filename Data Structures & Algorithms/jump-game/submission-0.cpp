class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[n-1] = true;
        for(int i = n-2; i >= 0; i--){
            int curr = nums[i];
            for(int j = 1; j <= curr; j++){
                if(i+j >= n){
                    break;
                }
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
