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
    int getSum(TreeNode* root,int& res){
        if(root==NULL)
            return 0;
        int left=getSum(root->left,res);
        int right=getSum(root->right,res);
        res+=abs(left-right);
        return root->val+left+right;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        getSum(root,res);
        return res;
    }
};