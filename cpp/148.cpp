/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // merge-sort
class Solution {
public:
	ListNode *mergeList(ListNode *a, ListNode *b){
		if(a==NULL)return b;
		if(b==NULL)return a;
		ListNode *res;
		if(a->val<b->val){
			res=a;
			a=a->next;
		}
		else{
			res=b;
			b=b->next;
		}
		res->next=mergeList(a,b);
		return res;
	}
    ListNode *sortList(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *head1,*head2;
        head1=head2=head;
        while(head2->next!=NULL&&head2->next->next!=NULL){
        	head1=head1->next;
        	head2=head2->next->next;
        }
        if(head1->next==NULL) return head;
        head2=head1->next;
        head1->next=NULL;
        head1=head;
        return mergeList(sortList(head1),sortList(head2));
    }
};

//quick-sort,will tle.
class Solution {
public:
	ListNode *getPartion(ListNode *beg, ListNode *end){
		int key = beg->val;
		ListNode *p = beg,
				 *q = beg->next;
		while(q!=end){
			if(q->val<key){
				p=p->next;
				swap(p->val,q->val);
			}
			q=q->next;
		}
		swap(p->val,beg->val);
		return p;
	}
	void quickSort(ListNode *beg, ListNode *end){
		if(beg!=end){
			ListNode *partion = getPartion(beg,end);
			quickSort(beg,partion);
			quickSort(partion->next,end);
		}
	}
    ListNode *sortList(ListNode *head) {
    	quickSort(head,NULL);
    	return head;
    }
};