class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }
        isEnd = false;
    }
    void insert(string word){
        TrieNode* curr = this;
        for(char c : word){
            if(curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
};

void dfs(vector<vector<char>>& board, int i, int j, string curr, TrieNode* node, set<string>& res){
    if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '*'){
        return;
    }
    char c = board[i][j];
    if(node->children[c-'a'] == nullptr) return;
    board[i][j] = '*';
    curr += c;
    node = node->children[c-'a'];
    if(node->isEnd){
        res.insert(curr);
    }
    dfs(board, i+1, j, curr, node, res);
    dfs(board, i, j+1, curr, node, res);
    dfs(board, i-1, j, curr, node, res);
    dfs(board, i, j-1, curr, node, res);
    curr.pop_back();
    board[i][j] = c;
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string s : words){
            root->insert(s);
        }

        set<string> res;
        string curr = "";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                char c = board[i][j];
                if(root->children[c-'a'] != nullptr){
                    dfs(board, i, j, curr, root, res);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
