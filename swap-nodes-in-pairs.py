# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy: ListNode = ListNode
        holder: ListNode = ListNode
        holder.next = head
        dummy.next = holder
        i = 0
        while head != None:
            if(i % 2 == 0):
                if head.next == None:
                    break
                holder.next = head.next
                tmp = head
                tmp2 = head.next
                tmp.next = tmp2.next
                tmp2.next = tmp
                holder = holder.next
            else:
                head = head.next
                holder = holder.next
            i += 1
        if i == 0:
            return head
        return dummy.next
