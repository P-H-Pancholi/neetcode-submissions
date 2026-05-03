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

class Solution {
public:
    void inorderTravsal(TreeNode* node, vector<int>& res){
        if(!node){
            return;
        }
        inorderTravsal(node->left, res);
        res.push_back(node->val);
        inorderTravsal(node->right, res);
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        vector<int> res;
        inorderTravsal(root, res);
        int prev = res[0];
        for(int i = 1; i < res.size(); i++){
            if(res[i] <= prev){
                return false;
            }
            prev = res[i];
        }
        return true;
    }
};
