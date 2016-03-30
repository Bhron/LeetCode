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
    func rotateRight(head: ListNode?, _ k: Int) -> ListNode? {
        if head == nil || k == 0 {
            return head
        }

        var length = 1
        var tail = head
        while tail!.next != nil {
            length += 1
            tail = tail!.next
        }

        let n = k % length
        if n == 0 {
            return head
        }

        let dummy = ListNode(0)
        dummy.next = head
        var node: ListNode? = dummy
        for var i = 0; i < length - n; i++ {
            node = node!.next
        }

        let newHead = node!.next
        tail!.next = dummy.next
        node!.next = nil

        return newHead
    }
}
