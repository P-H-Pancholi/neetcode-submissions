class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_largest(n);
        int temp = 0;
        for(int i = 0; i < n; i++){
            left_largest[i] = temp;
            temp = max(temp, height[i]);
        }
        vector<int> right_largest(n);
        temp = 0;
        for(int i = n-1; i >= 0; i--){
            right_largest[i] = temp;
            temp = max(temp, height[i]);
        }
        int max_area = 0;
        for(int i = 0; i < n; i++){
            int curr = min(right_largest[i], left_largest[i]);
            if(curr > height[i]){
                max_area += (curr - height[i]);
            }
        }
        return max_area;
    }
};
