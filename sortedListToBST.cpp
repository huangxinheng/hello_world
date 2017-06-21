/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* last=head;
        while(fast->next && fast->next->next){
            last=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid=slow->next;
        last->next=NULL;
        TreeNode* root=new TreeNode(slow->val);
        if(head!=slow)
            root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid);
        return root;
    }
};