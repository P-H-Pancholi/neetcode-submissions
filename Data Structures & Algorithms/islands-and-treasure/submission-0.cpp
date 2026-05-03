class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j, int res){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == -1){
            return;
        }
        
        if(res != 0 && grid[i][j] <= res){
            return;
        }
        grid[i][j] = res;
        bfs(grid, i+1, j, res+1);
        bfs(grid, i, j+1, res+1);
        bfs(grid, i-1, j, res+1);
        bfs(grid, i, j-1, res+1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0){
                    bfs(grid, i, j, 0);
                }
            }
        }
    }
};
