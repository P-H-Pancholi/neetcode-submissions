class Solution {
   public:
    unordered_map<char, unordered_set<char>> adjList;
    unordered_map<char, bool> visited;
    string result;
    bool dfs(char ch) {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];
        }
        visited[ch] = true;
        for (char c : adjList[ch]) {
            if (dfs(c)) {
                return true;
            }
        }
        result += ch;
        visited[ch] = false;
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        for(string word : words){
            for(char c : word){
                adjList[c];
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            int minLength = min(word1.size(), word2.size());
            if (word1.size() > word2.size() && word1.substr(0, minLength) == word2) {
                return "";
            }
            for (int i = 0; i < minLength; i++) {
                if (word1[i] != word2[i]) {
                    adjList[word1[i]].insert(word2[i]);
                    break;
                }
            }
        }

        for (auto& it : adjList) {
            if (dfs(it.first)) {
                return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
