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
	void _next(ListNode *&t){
		t = t->next;
	}
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
 		int clen = 0;
 		for(auto p = ha; p; _next(p)) clen++;
 		for(auto p = hb; p; _next(p)) --clen;       
 		while(clen > 0)_next(ha), --clen;
 		while(clen < 0)_next(hb), ++clen;
 		while(ha != hb)_next(ha), _next(hb); 
 		return ha;
    }
};