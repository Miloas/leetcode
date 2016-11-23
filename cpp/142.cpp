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
    ListNode *detectCycle(ListNode *head) {
    	if(!head)return NULL;
        ListNode *p=head,*q=p->next;
        while(p!=q && (q&&q->next)){
        	p=p->next;
        	q=q->next->next;
        }
        if(!q||!q->next)return NULL;
        int ct=1;
        q=q->next;
        while(p!=q){
        	ct++;
        	q=q->next;
        }
        p=q=head;
        while(ct--)q=q->next;
        while(p!=q)p=p->next,q=q->next;
        return p;
    }
};