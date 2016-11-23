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
  ListNode *reverseBetween(ListNode *list, int m, int n) {
  	ListNode *head = new ListNode(1729);
    head->next=list;
    ListNode *p,*q,*r,*pre=head;
    for(int i=0;i<m-1;++i)
    	pre=pre->next;
    p=pre->next;
    q=p->next;
    if(!q)return list;
    r=q->next;
    for(int i=m;i<n;++i){
    	q->next=p;
    	p=q;
    	q=r;
    	if(!r)break;
    	r=r->next;
    }
    pre->next->next=q;
    pre->next=p;
    return head->next;
  }
};
