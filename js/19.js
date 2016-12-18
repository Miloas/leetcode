/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
  let h = new ListNode(0)
  h.next = head 
  let p = h, q = h 
  while(n--)q = q.next 
  while(q.next) p = p.next,q = q.next 
  let t = p.next
  p.next = p.next.next 
  t = null
  return h.next
};