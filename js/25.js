/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
	let h = new ListNode(-1)
	h.next = head 
	let n = 0, p = head, q = h, first = true
	while (p) n++,p = p.next;
	p = h
	while(p.next) {
		if (n >= k) {
			let tk = k
			while (tk--) {
				let tp = p.next
				p.next = p.next.next
				tp.next = q.next 
				q.next = tp
				if(first) p = p.next, first = false
			}
			q = p
			n -= k
      first = true
		} else {
			return h.next
		}
	}
	return h.next
};