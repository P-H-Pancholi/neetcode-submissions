class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_product(n+1);
        prefix_product[0] = 1;
        vector<int> suffix_product(n+1);
        suffix_product[n] = 1;
        for(int i = 0; i < n; i++){
            prefix_product[i+1] = prefix_product[i] * nums[i];
            suffix_product[n-i-1] = suffix_product[n-i] * nums[n-i-1];
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = prefix_product[i] * suffix_product[i+1];
        }
        return res;
    }
};
