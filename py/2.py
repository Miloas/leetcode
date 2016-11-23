# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        c = 0
        ret = ListNode(-1)
        pos = ret
        while l1 or l2 or c :
            v = c
            if l1 :
                v += l1.val
                l1 = l1.next
            if l2 :
                v += l2.val
                l2 = l2.next
            c = v / 10
            v %= 10
            pos.next = ListNode(v)
            pos = pos.next
        return ret.next
            
