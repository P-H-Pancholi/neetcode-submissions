class Solution {
public:
    void createAdjacancyList(string beginWord, vector<string> &wordList, 
    unordered_map<string,set<string>> &graph){
        unordered_map<string, set<string>> pattern;
        
        for(int i = 0; i < beginWord.size(); i++){
            string temp = beginWord;
            temp[i] = '*';
            pattern[temp].insert(beginWord);
        }
        
        for(string s : wordList){
            for(int i = 0; i < s.size(); i++){
                string temp = s;
                temp[i] = '*';
                pattern[temp].insert(s);
            }
        }

        for(int i = 0; i < beginWord.size(); i++){
            string temp = beginWord;
            temp[i] = '*';
            for(string s : pattern[temp]){
                if(s != beginWord){
                    graph[beginWord].insert(s);
                    graph[s].insert(beginWord);
                }
            }
        }

        for(string s : wordList){
            for(int i = 0; i < s.size(); i++){
                string temp = s;
                temp[i] = '*';
                for(string t : pattern[temp]){
                    if(t != s){
                        graph[t].insert(s);
                        graph[s].insert(t);
                    }
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, set<string>> graph;
        createAdjacancyList(beginWord, wordList, graph);
        if(graph.find(endWord) == graph.end()){
            return 0;
        }
        int res = 1;
        queue<string> q;
        q.push(beginWord);
        set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string curr = q.front();
                if(curr == endWord){
                    return res;
                }
                q.pop();
                for(string s : graph[curr]){
                    if(visited.find(s) == visited.end()){
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
