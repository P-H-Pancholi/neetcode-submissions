class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0, end = heights.size()-1;
        int maximum = 0;
        while(start < end){
            maximum = max(min(heights[start], heights[end])*(end-start), maximum);
            if(heights[start] > heights[end]){
                end--;
            }else{
                start++;
            }
        }
        return maximum;
    }
};
