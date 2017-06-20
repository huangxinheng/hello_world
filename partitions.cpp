/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        ListNode* a=new ListNode(0);
        ListNode* b=new ListNode(0);
        ListNode* pSmall=a;
        ListNode* pLarge=b;
        while(head){
            if(head->val<x){
                pSmall->next=head;
                pSmall=head;
            }else{
                pLarge->next=head;
                pLarge=head;
            }
            head=head->next;
        }
        pLarge->next=NULL;
        pSmall->next=b->next;
        return a->next;
    }
};