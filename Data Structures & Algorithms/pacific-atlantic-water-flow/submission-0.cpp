class Solution {
public:
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        stack<pair<int,int>> st;
        for(int i = 0; i < m; i++){
            pacific[i][0] = true;
            st.push({i,0});
        }
        for(int i = 0; i < n; i++){
            pacific[0][i] = true;
            st.push({0,i});
        }
        while(!st.empty()){
            int i = st.top().first, j = st.top().second;
            st.pop();
            vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            for(int k = 0; k < 4; k++){
                int curr_i = i+dirs[k][0];
                int curr_j = j+dirs[k][1];
                if(curr_i < 0 || curr_i == m || curr_j < 0 || curr_j == n || 
                pacific[curr_i][curr_j]) continue;
                if(heights[curr_i][curr_j] >= heights[i][j]){
                    pacific[curr_i][curr_j] = true;
                    st.push({curr_i, curr_j});
                }
            }
        }
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            atlantic[i][n-1] = true;
            st.push({i, n-1});
        }
        for(int i = 0; i < n; i++){
            atlantic[m-1][i] = true;
            st.push({m-1,i});
        }
        while(!st.empty()){
            int i = st.top().first, j = st.top().second;
            st.pop();
            vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            for(int k = 0; k < 4; k++){
                int curr_i = i+dirs[k][0];
                int curr_j = j+dirs[k][1];
                if(curr_i < 0 || curr_i == m || curr_j < 0 || curr_j == n || 
                atlantic[curr_i][curr_j]) continue;
                if(heights[curr_i][curr_j] >= heights[i][j]){
                    atlantic[curr_i][curr_j] = true;
                    st.push({curr_i, curr_j});
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
