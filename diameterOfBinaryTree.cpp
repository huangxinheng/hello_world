/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxHeight(TreeNode* root){
        if(root==NULL)
            return 0;
        int res=1+max(maxHeight(root->left),maxHeight(root->right));
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=maxHeight(root->left)+maxHeight(root->right);
        return max(res,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};