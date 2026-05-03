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
    void recursiveFunc(TreeNode* node){
        if(!node){
            return;
        }
        TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
        recursiveFunc(node->right);
        recursiveFunc(node->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        recursiveFunc(root);
        return root;
    }
};
