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
    void in_order(TreeNode* root,int& prev,int& m){
        if(root==NULL)
            return;
        in_order(root->left,prev,m);
        if(prev!=-1){
            m=min(m,root->val-prev);
        }
        prev=root->val;
        in_order(root->right,prev,m);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
            return 0;
        int prev=-1;
        int res=INT_MAX;
        in_order(root,prev,res);
        return res;
    }
};