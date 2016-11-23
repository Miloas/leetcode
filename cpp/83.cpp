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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)return NULL;
        int x = head->val;
        ListNode *p=head->next,*pre=head;
        while(p){
        	if(p->val==x){
        		ListNode *q=p;
        		pre->next=p->next;
        		p=p->next;
        		delete q;
        	}
        	else {
        		x = p->val;
        		pre=pre->next;
        		p=p->next;
        	}
        }
        return head;
    }
};