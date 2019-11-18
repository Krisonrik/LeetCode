# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        NodeHolder = []
        head_node = head
        while head != None:
            NodeHolder.append(head)
            head = head.next
        sz = len(NodeHolder)
        print(sz)
        if n == sz:
            if(sz != 1):
                head_node = NodeHolder[1]
            else:
                return None
        elif n == 1:
            NodeHolder[sz-2].next = None
        else:
            NodeHolder[len(NodeHolder) - 1 -
                       n].next = NodeHolder[len(NodeHolder) - n+1]
        return head_node
