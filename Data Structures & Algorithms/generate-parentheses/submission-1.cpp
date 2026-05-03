class Solution {
public:
    void RecFunc(vector<string> &res, int n, int open, int close, string curr){
        if(curr.size() == 2*n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            RecFunc(res, n, open+1, close, curr+'(');
        }
        if(close < open){
            RecFunc(res, n, open, close+1, curr+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        RecFunc(res, n, 0, 0, curr);
        return res;
    }
};
