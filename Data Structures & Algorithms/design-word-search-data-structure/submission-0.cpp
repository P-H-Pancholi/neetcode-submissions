class TrieNode {
public:
    TrieNode* children[26];
    bool isEndNode;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }
        this->isEndNode = false;
    }
};
class WordDictionary {
private:
    bool backtrack(string word, int index, TrieNode* curr){
        if(index == word.size()){
            return curr->isEndNode;
        }
        if(word[index] == '.'){
            for(int i = 0; i < 26; i++){
                if(curr->children[i]){
                    if(backtrack(word, index+1, curr->children[i])) return true;
                }
            }
        }else{
            if(!curr->children[word[index]-'a']){
                return false;
            }
            return backtrack(word, index+1, curr->children[word[index]-'a']);
        }
        return false;
    }
public:
    TrieNode* root;
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return backtrack(word, 0, this->root);
    }
};
