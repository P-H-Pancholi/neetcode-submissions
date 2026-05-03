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
    void dfs(TreeNode* node, int& smaller, int& res, int k){
        if(node == nullptr){
            return;
        }
        dfs(node->left, smaller, res, k);
        smaller++;
        if(smaller==k){
            res = node->val;
        }
        dfs(node->right, smaller, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int s = 0, res = 0;
        dfs(root, s, res, k);
        return res;
    }
};
