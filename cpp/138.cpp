/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head)return NULL;
        RandomListNode *p=head,*q,*res;
        while(p){
        	q=new RandomListNode(p->label);
        	q->next=p->next;
        	p->next=q;
        	p=q->next;
        }
        for(p=head;p;){
        	q=p->next;
        	if(p->random)
        		q->random=p->random->next;
        	p=q->next;
        }
        res=head->next;
 	   for (p = head; p; p = p->next) {
	      q = p->next;
	      p->next = q->next;
	      if (q->next)
	        q->next = q->next->next;
	    }
        return res;
    }
};