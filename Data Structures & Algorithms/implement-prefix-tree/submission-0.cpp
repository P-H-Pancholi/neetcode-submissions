class TrieNode{
public:
    vector<TrieNode*> children;
    bool isEndNode;

    TrieNode() {
        for(int i = 0; i < 26; i++){
            this->children.push_back(nullptr);
        }
        this->isEndNode = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = this->root;
        for(char c : word){
            if(!curr->children[c-'a']){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEndNode = true;
    }
    
    bool search(string word) {
        TrieNode* curr = this->root;
        for(char c : word){
            if(!curr->children[c-'a']) return false;
            curr = curr->children[c-'a'];
        }
        return curr->isEndNode;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = this->root;
        for(char c : prefix){
            if(!curr->children[c-'a']) return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};
