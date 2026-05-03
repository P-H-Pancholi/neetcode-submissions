class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        for(int i = 0; i < n; i++){
            if(i == 0){
                prefix[0] = height[0];
                suffix[n-1] = height[n-1];
            }else{
                if(height[i] > prefix[i-1]){
                    prefix[i] = height[i];
                }else{
                    prefix[i] = prefix[i-1];
                }

                if(height[n-i-1] > suffix[n-i]){
                    suffix[n-i-1] = height[n-i-1];
                }else{
                    suffix[n-i-1] = suffix[n-i];
                }
            }
        }
        int water = 0;
        for(int i = 0; i < n; i++){
            water += max(min(prefix[i], suffix[i])-height[i], 0);
        }
        return water;
    }
};
