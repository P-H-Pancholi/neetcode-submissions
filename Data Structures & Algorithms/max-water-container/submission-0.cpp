class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size()-1;
        int ans = INT_MIN;
        while(start < end){
            int curr = min(heights[start], heights[end])*(end-start);
            ans = max(ans,curr);
            if(heights[start] < heights[end]){
                start++;
            }else{
                end--;
            }
        }
        return ans;
    }
};
