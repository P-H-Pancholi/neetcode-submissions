class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>> &visited, 
        int x, int y, int currIndex, string word){
        if(x == board.size() || y == board[x].size() || x < 0 || y < 0 || visited[x][y]){
            return false;
        }
        if(board[x][y] != word[currIndex]){
            return false;
        }
        visited[x][y] = true;
        currIndex++;
        if(currIndex == word.size()){
            return true;
        }
        if(backtrack(board, visited, x-1, y, currIndex, word)){
            return true;
        }
        if(backtrack(board, visited, x, y-1, currIndex, word)){
            return true;
        }
        if(backtrack(board, visited, x+1, y, currIndex, word)){
            return true;
        }
        if(backtrack(board, visited, x, y+1, currIndex, word)){
            return true;
        }
        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    if (backtrack(board, visited, i, j, 0, word)) return true;
                }
            }
        }
        return false;
    }
};
