class Solution {
public:
    void backtrack(int openP, int closeP, int n, 
        vector<string> &res, string &stack) {
            if(openP == closeP && openP == n){
                res.push_back(stack);
                return;
            }
            if(openP < n){
                stack += "(";
                backtrack(openP+1, closeP, n, res, stack);
                stack.pop_back();
            }
            if(closeP < openP){
                stack += ")";
                backtrack(openP, closeP+1, n, res, stack);
                stack.pop_back();
            }
        }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        backtrack(0, 0, n, res, s);
        return res;
    }
};
