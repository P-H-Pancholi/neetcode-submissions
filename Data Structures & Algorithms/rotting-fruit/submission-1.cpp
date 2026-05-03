class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int noOfFresh = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    noOfFresh++;
                }
            }
        }
        int res = 0;
        while(!q.empty() && noOfFresh != 0){
            int size = q.size();
            for(int k = 0; k < size; k++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                vector<vector<int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
                for(int i = 0; i < 4; i++){
                    int curr_i = x+dirs[i][0];
                    int curr_j = y+dirs[i][1];
                    if(curr_i < 0 || curr_i == grid.size() || 
                    curr_j < 0 || curr_j == grid[curr_i].size() || grid[curr_i][curr_j] == 0){
                        continue;
                    }
                    if(grid[curr_i][curr_j] == 1){
                        noOfFresh--;
                        grid[curr_i][curr_j] = 2;
                        q.push({curr_i, curr_j});
                    }
                }
            }
            res++;
        }
        return noOfFresh==0?res:-1;
    }
};