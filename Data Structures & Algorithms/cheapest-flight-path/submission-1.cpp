class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        while(k+1){
            vector<int> tmp = prices;
            for(vector<int> v : flights){
                if(prices[v[0]] != INT_MAX){
                    tmp[v[1]] = min(tmp[v[1]], prices[v[0]] + v[2]);
                }
            }
            prices = tmp;
            k--;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};