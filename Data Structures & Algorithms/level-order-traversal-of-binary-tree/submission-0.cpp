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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> temp;
            vector<int> curr;
            while(!q.empty()){
                TreeNode* currNode = q.front();
                q.pop();
                curr.push_back(currNode->val);
                if(currNode->left){
                    temp.push(currNode->left);
                }
                if(currNode->right){
                    temp.push(currNode->right);
                }
            }
            q = temp;
            res.push_back(curr);
        }
        return res;
    }
};
