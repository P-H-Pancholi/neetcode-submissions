class Solution {
public:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>> &cache){
        if(i == s.size()) {
            while(j < p.size()){
                if(j+1 >= p.size() || p[j+1] != '*') return false;
                j += 2;
            }
            return true;
        }
        if(j == p.size()) return false;
        if(cache[i][j] != -1){
            return cache[i][j];
        }
        bool result = false;
        bool charMatch = (p[j] == '.' || p[j] == s[i]);
        if(j+1 < p.size() && p[j+1] == '*'){
            if(charMatch){
                result = dfs(i+1, j, s, p, cache);
            }
            if(!result){
                result = dfs(i, j+2, s, p, cache);
            }
        }else{
            if(charMatch){
                result = dfs(i+1, j+1, s, p, cache);
            }
        }
        cache[i][j] = result;
        return cache[i][j];
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.size(), vector<int>(p.size(), -1));
        return dfs(0,0,s,p,cache);
    }
};
