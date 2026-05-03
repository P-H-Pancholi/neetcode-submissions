class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0, curr_max = INT_MIN;
        for(int i = prices.size()-1; i >= 0; i--){
            curr_max = max(curr_max, prices[i]);
            maximum = max(maximum, curr_max-prices[i]);
        }
        return maximum;
    }
};
