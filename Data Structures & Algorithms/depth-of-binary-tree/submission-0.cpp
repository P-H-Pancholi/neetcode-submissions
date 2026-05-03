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
    void dfs(TreeNode* node, int level, int &maxlevel){
        if(!node){
            return;
        }
        maxlevel = max(level, maxlevel);
        dfs(node->left, level+1, maxlevel);
        dfs(node->right, level+1, maxlevel);
    }
    int maxDepth(TreeNode* root) {
        int res = 0;
        dfs(root, 1, res);
        return res;
    }
};
