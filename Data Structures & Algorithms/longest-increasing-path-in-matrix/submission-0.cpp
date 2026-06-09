class Solution {
public:
    int backtrack(vector<vector<int>> &cache, vector<vector<int>>& matrix, int i, int j){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size()){
            return 0;
        }
        if(cache[i][j] != -1) return cache[i][j];
        int curr = 1;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(vector<int> v : dirs){
            int curr_i = i+v[0], curr_j = j+v[1];
            if(curr_i < 0 || curr_i >= matrix.size() || curr_j < 0 || curr_j >= matrix[curr_i].size()){
                continue;
            }
            if(matrix[curr_i][curr_j] > matrix[i][j]){
                curr = max(curr, 1+backtrack(cache, matrix, curr_i, curr_j));
            }
        }
        cache[i][j] = curr;
        return curr;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, backtrack(cache, matrix, i, j));
            }
        }
        return res;
    }
};
