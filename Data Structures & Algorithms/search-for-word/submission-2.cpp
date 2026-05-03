class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>> &visited, 
        int x, int y, int wordIndex, string word){
        if(wordIndex == word.size()){
            return true;
        }
        if(x+1 < board.size() && !visited[x+1][y] && board[x+1][y] == word[wordIndex]){
            visited[x+1][y] = true;
            bool r = backtrack(board, visited, x+1, y, wordIndex+1, word);
            if(r){
                return true;
            }
            visited[x+1][y] = false;
        }
        if(y+1 < board[x].size() && !visited[x][y+1] && board[x][y+1] == word[wordIndex]){
            visited[x][y+1] = true;
            bool r = backtrack(board, visited, x, y+1, wordIndex+1, word);
            if(r){
                return true;
            }
            visited[x][y+1] = false;
        }
        if(x-1 >= 0 && !visited[x-1][y] && board[x-1][y] == word[wordIndex]){
            visited[x-1][y] = true;
            bool r = backtrack(board, visited, x-1, y, wordIndex+1, word);
            if(r){
                return true;
            }
            visited[x-1][y] = false;
        }
        if(y-1 >= 0 && !visited[x][y-1] && board[x][y-1] == word[wordIndex]){
            visited[x][y-1] = true;
            bool r = backtrack(board, visited, x, y-1, wordIndex+1, word);
            if(r){
                return true;
            }
            visited[x][y-1] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if (backtrack(board, visited, i, j, 1, word)) return true;
                }
            }
        }
        return false;
    }
};
