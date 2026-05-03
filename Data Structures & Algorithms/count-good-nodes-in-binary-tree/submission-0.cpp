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
    void dfs(TreeNode* node, int maxvalue, int &goodNodes){
        if(!node){
            return;
        }
        if(node->val >= maxvalue){
            goodNodes++;
            maxvalue = node->val;
        }
        dfs(node->left, maxvalue, goodNodes);
        dfs(node->right, maxvalue, goodNodes);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};
