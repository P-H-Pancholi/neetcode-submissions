class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int sz = grid.size();
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        pq.push({grid[0][0], {0,0}});
        set<pair<int,int>> st;
        int res = grid[0][0];
        while(pq.size()){
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();
            if(st.find({curr.second.first, curr.second.second}) != st.end()) continue;
            st.insert(curr.second);
            res = max(res, curr.first);
            if(curr.second.first == sz-1 && curr.second.second == sz-1){
                return res;
            }
            vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            for(int i = 0; i < 4; i++){
                int curr_x = curr.second.first + dirs[i][0];
                int curr_y = curr.second.second + dirs[i][1];
                if(curr_x < 0 || curr_y < 0 || curr_x >= sz || curr_y >= sz || st.find({curr_x, curr_y}) != st.end()){
                    continue;
                }
                pq.push({grid[curr_x][curr_y], {curr_x, curr_y}});
            }
        }
        return res;
    }
};
