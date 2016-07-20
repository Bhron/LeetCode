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
    func deleteDuplicates(head: ListNode?) -> ListNode? {
        if head == nil || head!.next == nil {
            return head
        }

        var current = head
        while current!.next != nil {
            let value = current!.val
            if current!.next!.val == value {
                var node = current!.next
                while node != nil && node!.val == value {
                    node = node!.next
                }
                current!.next = node
            } else {
                current = current!.next
            }
        }

        return head
    }
}
