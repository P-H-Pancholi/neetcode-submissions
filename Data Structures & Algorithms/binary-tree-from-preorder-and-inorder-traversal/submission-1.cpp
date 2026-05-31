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
private:
    TreeNode* recHelper(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preEnd < preStart || inEnd < inStart) return nullptr;
        int curr = preorder[preStart];
        TreeNode* root = new TreeNode(curr);
        int idx = find(inorder.begin(), inorder.end(), curr) - inorder.begin();
        int leftSize = idx-inStart;
        root->left = recHelper(preStart+1, preStart+leftSize, inStart, idx-1, preorder, inorder);
        root->right = recHelper(preStart+leftSize+1, preEnd, idx+1, inEnd, preorder, inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recHelper(0, preorder.size()-1,0, inorder.size()-1, preorder, inorder);
    }
};
