/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        stack<Node*> st;
        st.push(node);
        set<int> visited;
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            Node* newNode = new Node(curr->val);
            visited.insert(curr->val);
            mp[curr] = newNode;
            for(Node* temp : curr->neighbors){
                if(visited.find(temp->val) == visited.end()){
                    st.push(temp);
                }
            }
        }
        visited.clear();
        st.push(node);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            Node* newNode = mp[curr];
            visited.insert(curr->val);
            vector<Node*> newNeighbors;
            for(Node* temp : curr->neighbors){
                newNeighbors.push_back(mp[temp]);
                if(visited.find(temp->val) == visited.end()) st.push(temp);
            }
            newNode->neighbors = newNeighbors;
        }
        return mp[node];
    }
};
