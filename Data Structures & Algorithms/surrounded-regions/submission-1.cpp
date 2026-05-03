class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> canReach(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                canReach[i][0] = true;
            }
            if(board[i][n-1] == 'O'){
                q.push({i,n-1});
                canReach[i][n-1] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                canReach[0][i] = true;
            }
            if(board[m-1][i] == 'O'){
                q.push({m-1,i});
                canReach[m-1][i] = true;
            }
        }
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            for(int k = 0; k < 4; k++){
                int curr_i = i + dirs[k][0];
                int curr_j = j + dirs[k][1];
                if(curr_i < 0 || curr_i == m || 
                curr_j < 0 || curr_j == n || 
                canReach[curr_i][curr_j] || board[curr_i][curr_j] == 'X') continue;
                q.push({curr_i, curr_j});
                canReach[curr_i][curr_j] = true;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !canReach[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
