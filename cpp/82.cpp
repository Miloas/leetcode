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
    	if(!head||!head->next)return head;
    	ListNode *p=head->next;
    	while(p&&p->val==head->val){
    		ListNode *q=p;
    		p=p->next;
    		delete q;
    	}
    	if(!p)return p;
    	if(p==head->next){
    		head->next=deleteDuplicates(p);
    		return head;
    	}
    	else return deleteDuplicates(p);
    }
};