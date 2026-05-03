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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root){
            return {};
        }
        q.push(root);
        while(!q.empty()){
            vector<int> curr;
            queue<TreeNode*> temp;
            while(!q.empty()){
                TreeNode* currNode = q.front();
                q.pop();
                curr.push_back(currNode->val);
                if(currNode->right){
                    temp.push(currNode->right);
                }
                if(currNode->left){
                    temp.push(currNode->left);
                }
            }
            q = temp;
            res.push_back(curr[0]);
        }
        return res;
    }
};
