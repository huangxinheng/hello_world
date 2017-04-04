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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* res=NULL;
        ListNode* cur;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int r1=l1?l1->val:0;
            int r2=l2?l2->val:0;
            int sum = r1+r2+carry;
            carry = sum/10;
            if(res==NULL){
                res=new ListNode(sum%10);
                cur=res;
            }else{
                ListNode* tmp=new ListNode(sum%10);
                cur->next=tmp;
                cur=cur->next;
            }
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        if(carry)
            cur->next=new ListNode(carry);
        return res;
    }
};