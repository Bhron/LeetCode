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
    func partition(head: ListNode?, _ x: Int) -> ListNode? {
        if head == nil {
            return head
        }

        let lessDummy = ListNode(0)
        let greaterEqualDummy = ListNode(0)
        var lessNode: ListNode? = lessDummy
        var greaterEqualNode: ListNode? = greaterEqualDummy

        var node = head
        while node != nil {
            if node!.val < x {
                lessNode!.next = node
                lessNode = lessNode!.next
            } else {
                greaterEqualNode!.next = node
                greaterEqualNode = greaterEqualNode!.next
            }
            node = node!.next
        }

        lessNode!.next = greaterEqualDummy.next
        greaterEqualNode!.next = nil

        return lessDummy.next
    }
}
