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
    void reorderList(ListNode *head) {
    	if(!head || !head->next || !head->next->next) return ;
    	ListNode *p = head, *q = p;
    	while(q->next&&q->next->next){
    		p = p->next;
    		q = q->next->next;
    	}
    	q=p->next;p->next=NULL;
    	while(q){
    	    ListNode *tmp = q->next;
    		q->next = p->next;
    		p->next = q;
    		q = tmp;
    	}
    	int flag = 1;
    	q = head;
    	while(p!=q){
    		if(flag){
    			ListNode *tmp = p->next;
    			p->next = tmp->next;
    			tmp->next = q->next;
    			q->next = tmp; 
    		}
    		q = q->next;
    		flag ^= 1;
    	}
    }
};