class Solution {
public:
    int dfs(string& word1, string& word2, int i, int j, vector<vector<int>>& cache){
        if(i == word1.size()) return (int)(word2.size()-j);
        if(j == word2.size()) return (int)(word1.size()-i);
        if(cache[i][j] != -1){
            return cache[i][j];
        }
        int curr;
        if(word1[i] == word2[j]){
            curr = dfs(word1, word2, i+1, j+1, cache);
        }else{
            curr = 1+min(
                dfs(word1, word2, i+1, j+1, cache), 
                min(
                    dfs(word1, word2, i,j+1, cache),
                    dfs(word1, word2, i+1,j, cache)  
                ));
        }
        cache[i][j] = curr;
        return curr;
    }
    int minDistance(string word1, string word2) {
        int i = 0, j = 0;
        vector<vector<int>> cache(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, word2, i, j , cache);
    }
};
