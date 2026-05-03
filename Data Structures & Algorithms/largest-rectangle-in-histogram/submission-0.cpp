class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int res = 0, i = 0;
        while(i < heights.size()){
            int index = i;
            while(!st.empty() && st.top().second > heights[i]){
                int curr_height = st.top().second;
                int curr_index = st.top().first;
                res = max(res, (i-curr_index)*curr_height);
                index = curr_index;
                st.pop();
            }
            st.push({index, heights[i]});
            i++;
        }
        while(!st.empty()){
            int curr_height = st.top().second;
            int curr_index = st.top().first;
            res = max(res, (i-curr_index)*curr_height);
            st.pop();
        }
        return res;
    }
};
