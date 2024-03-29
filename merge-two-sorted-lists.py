# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None and l2 == None:
            return None
        holder: ListNode = ListNode
        dummy: ListNode = ListNode
        dummy.next = holder
        while l1 != None and l2 != None:
            if l1.val > l2.val or l1 == None:
                holder.next = l2
                l2 = l2.next
            else:
                holder.next = l1
                l1 = l1.next
            holder = holder.next

        while l1 != None:
            holder.next = l1
            l1 = l1.next
            holder = holder.next

        while l2 != None:
            holder.next = l2
            l2 = l2.next
            holder = holder.next

        return dummy.next
