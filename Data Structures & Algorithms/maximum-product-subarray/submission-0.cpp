class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1, n = nums.size(), res = INT_MIN;
        for(int i = 0; i < n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            res = max(res, max(prefix, suffix));
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }
        return res;
    }
};
