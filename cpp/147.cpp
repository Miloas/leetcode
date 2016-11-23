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
    ListNode *insertionSortList(ListNode *list) {
    	ListNode *head = new ListNode(1729);
    	head->next=list;
    	for(auto pre=head,p=head->next;p;){
    		auto q=head;
    		for(;q!=p;q=q->next){
    			if(q->next->val>p->val){
    				pre->next=p->next;
    				p->next=q->next;
    				q->next=p;
    				p=pre->next;
    				break;
    			}
    		}
    		if(p==q){
    			p=p->next;
    			pre=pre->next;
    		}
    	}
    	auto res=head->next;
    	head->next=NULL;delete head;
    	return res;
    }
};