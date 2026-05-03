class Solution {
public:
    void backtrack(vector<vector<string>> &res, vector<string> curr, 
    set<int> cols, set<int> postDiag, set<int> negDiag, int n, int row){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < n; i++){
            if(cols.find(i) == cols.end() && 
                postDiag.find(i+row) == postDiag.end() &&
                negDiag.find(row-i) == negDiag.end()){
                string currStr = "";
                for(int j = 0; j < n; j++){
                    if(j == i){
                        currStr += "Q";
                    }else{
                        currStr += ".";
                    }
                }
                cols.insert(i);
                postDiag.insert(i+row);
                negDiag.insert(row-i);
                curr.push_back(currStr);
                backtrack(res, curr, cols, postDiag, negDiag, n, row+1);
                cols.erase(i);
                postDiag.erase(i+row);
                negDiag.erase(row-i);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        backtrack(res, {}, {}, {}, {}, n, 0);
        return res;
    }
};
