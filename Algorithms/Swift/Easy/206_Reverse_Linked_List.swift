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
    func reverseList(head: ListNode?) -> ListNode? {
        if head == nil {
            return nil
        }

        var prev: ListNode? = nil
        var node = head
        while node != nil {
            let tmp = node!.next;
            node!.next = prev
            prev = node
            node = tmp
        }

        return prev
    }
}
