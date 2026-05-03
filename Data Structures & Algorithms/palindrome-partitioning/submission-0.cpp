class Solution {
public:
    bool isPalin(string s){
        int start = 0, end = s.size()-1;
        while(end >= start){
            if(s[end] != s[start]){
                return false;
            }
            end--;start++;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &res, vector<string> curr, string s, int index){
        if(index >= s.size()){
            res.push_back(curr);
            return;
        }
        for(int i = index+1; i <= s.size(); i++){
            string currString = s.substr(index, i-index);
            if(isPalin(currString)){
                curr.push_back(currString);
                backtrack(res, curr, s, i);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        backtrack(res, {}, s, 0);
        return res;
    }
};
