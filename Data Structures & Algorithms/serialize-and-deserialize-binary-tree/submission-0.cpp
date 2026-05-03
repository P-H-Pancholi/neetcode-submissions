/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    void dfsSerialize(TreeNode* root, vector<string> &v){
        if(root == nullptr){
            v.push_back("N");
            return;
        }
        v.push_back(to_string(root->val));
        dfsSerialize(root->left, v);
        dfsSerialize(root->right, v);
    }

    TreeNode* dfsDeserialize(vector<string> v, int &i){
        if(v[i] == "N"){
            i++;
            return nullptr;
        }
        TreeNode* curr = new TreeNode(stoi(v[i]));
        i++;
        curr->left = dfsDeserialize(v,i);
        curr->right = dfsDeserialize(v,i);
        return curr;
    }

    vector<string> split(string s, char delim){
        stringstream ss(s);
        vector<string> res;
        string curr;
        while(getline(ss, curr, delim)){
            res.push_back(curr);
        }
        return res;
    }
    

    string join(vector<string> s, string delim){
        ostringstream oss;
        for(int i = 0; i < s.size(); i++){
            if(i > 0) oss << delim;
            oss << s[i];
        }
        return oss.str();
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values;
        values = split(data, ',');
        int i = 0;
        return dfsDeserialize(values, i);
    }
};
