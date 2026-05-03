class Solution {
public:
    void backtrack(vector<vector<char>>& grid, vector<vector<bool>>& isVisited, int i, int j){
        isVisited[i][j] = true;
        if(i+1 < grid.size() && grid[i+1][j] == '1' && !isVisited[i+1][j]){
            backtrack(grid, isVisited, i+1, j);
        }
        if(j+1 < grid[i].size() && grid[i][j+1] == '1' && !isVisited[i][j+1]){
            backtrack(grid, isVisited, i, j+1);
        }
        if(i-1 >= 0 && grid[i-1][j] == '1' && !isVisited[i-1][j]){
            backtrack(grid, isVisited, i-1, j);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1' && !isVisited[i][j-1]){
            backtrack(grid, isVisited, i, j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !isVisited[i][j]){
                    res++;

                    backtrack(grid, isVisited, i, j);
                }
            }
        }
        return res;
    }
};