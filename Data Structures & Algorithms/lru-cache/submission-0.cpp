class Node{
private:
    
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    int cap;
    Node* left;
    Node* right;

    void insert(Node* node){
        Node* temp = right->prev;
        right->prev = node;
        node->next = right;
        temp->next = node;
        node->prev = temp;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            cache[key]->val = value;
        }else{
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);
            if(cache.size() > cap){
                Node* lru = left->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};
// We will keep hashmap for storing key value pair, where key will be key and 
// value will be pointer to the node
// There will be doubly linkedlist and we will keep left pointer pointing to LRU
// and right pointer pointing to MRU
// when we try to get a node we will shift the pointers


