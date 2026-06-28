class Solution {
public:
    int dp(int left, int right, vector<int>& nums, vector<vector<int>> &cache){
        //cout << left << " " << right << endl;
        //cout << cache[left][right] << endl;
        if(left > right) return 0;
        if(cache[left][right] != -1) return cache[left][right];
        int res = 0;
        for(int i = left; i <= right; i++){
            // int curr = nums[left-1]*nums[i]*nums[right+1] + 
            // dp(left, i-1,nums,cache) + 
            // dp(i+1, right, nums, cache);
            int curr = nums[left-1]*nums[i]*nums[right+1];
            if(i != left){
                curr += dp(left, i-1,nums,cache);
            }
            if(i != right){
                curr += dp(i+1, right, nums, cache);
            }
            res = max(curr, res);
        }
        cache[left][right] = res;
        return res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        //cout << nums.size() << endl;
        vector<vector<int>> cache(nums.size(), vector<int>(nums.size(), -1));
        return dp(1, nums.size()-2, nums, cache);
    }
};
