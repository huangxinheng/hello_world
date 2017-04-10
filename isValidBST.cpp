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
    bool isBST(TreeNode* root,TreeNode* mn,TreeNode* mx){
        if(root==NULL)
            return true;
        if(mn && root->val<=mn->val)
            return false;
        if(mx && root->val>=mx->val)
            return false;
        return isBST(root->left,mn,root) && isBST(root->right,root,mx);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return isBST(root,NULL,NULL);
    }
};