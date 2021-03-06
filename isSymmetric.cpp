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
    bool left_right(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL)
            return true;
        if(left!=NULL && right==NULL)
            return false;
        if(left==NULL && right!=NULL)
            return false;
        return (left->val==right->val) && left_right(left->left,right->right)&&left_right(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return left_right(root->left,root->right);
    }
};