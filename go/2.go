/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	c := 0
	ret := &ListNode{-1, nil}
	pos := ret
	for l1 != nil || l2 != nil || c != 0 {
		v := c
		if l1 != nil {
			v = v + l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			v = v + l2.Val
			l2 = l2.Next
		}
		c = v / 10
		v = v % 10
		pos.Next = &ListNode{v, nil}
		pos = pos.Next
	}
	return ret.Next
}
