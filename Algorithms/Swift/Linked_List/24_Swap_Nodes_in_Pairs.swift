/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func swapPairs(head: ListNode?) -> ListNode? {
        if head == nil {
            return head
        }

        let dummy = ListNode(0)
        dummy.next = head

        var node: ListNode? = dummy
        while node!.next != nil && node!.next!.next != nil {
            var node1 = node!.next
            var node2 = node1!.next

            node1!.next = node2!.next
            node2!.next = node1
            node!.next = node2

            node = node!.next!.next
        }

        return dummy.next
    }
}
