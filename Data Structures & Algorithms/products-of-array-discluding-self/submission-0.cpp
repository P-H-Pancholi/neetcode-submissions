class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> sufix(n);
        for(int i = 0; i < n; i++) {
            if(i == 0){
                prefix[i] = nums[i];
                sufix[n-i-1] = nums[n-i-1];
            }else{
                prefix[i] = nums[i] * prefix[i-1];
                sufix[n-i-1] = nums[n-i-1] * sufix[n-i];
            }
        }
        vector<int> product(n);
        for(int i = 0; i < n; i++) {
            if(i == 0){
                product[i] = sufix[1];
            }
            else if(i == n-1){
                product[i] = prefix[n-2];
            }else{
                product[i] = prefix[i-1] * sufix[i+1];
            }
        }

        return product;
    }
};
