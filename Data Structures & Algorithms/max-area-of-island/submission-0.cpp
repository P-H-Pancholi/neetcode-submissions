class Solution {
public:
    int backtrack(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, 
    int i, int j, int &res){
        if(i >= grid.size() || i < 0 || 
        j >= grid[i].size() || j < 0 || grid[i][j] == 0 || isVisited[i][j]) return 0;
        isVisited[i][j] = true;
        int curr = 1 + 
        backtrack(grid, isVisited, i+1, j, res) + 
        backtrack(grid, isVisited, i, j+1, res) +
        backtrack(grid, isVisited, i-1, j, res) +
        backtrack(grid, isVisited, i, j-1, res);
        res = max(res, curr);
        return curr;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1 && !isVisited[i][j]){
                    backtrack(grid, isVisited, i, j, res);
                }
            }
        }
        return res;
    }
};
