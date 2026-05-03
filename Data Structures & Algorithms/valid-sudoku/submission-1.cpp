class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxs(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char curr_char = board[i][j];
                if(curr_char == '.'){
                    continue;
                }
                int curr = curr_char-49;
                if(rows[i][curr]){
                    return false;
                }
                rows[i][curr] = true;
                
                if(cols[j][curr]){
                    return false;
                }
                cols[j][curr] = true;
                
                int i_idx = i/3;
                int j_idx = j/3;
                int box_idx = 3*i_idx + j_idx;
                
                if(boxs[box_idx][curr]){
                    return false;
                }
                boxs[box_idx][curr] = true;
            }
        }
        return true; 
    }
};
