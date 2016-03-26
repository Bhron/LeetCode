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
    func mergeTwoLists(l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let dummy = ListNode(0)
        var node: ListNode? = dummy

        var list1 = l1
        var list2 = l2
        while list1 != nil && list2 != nil {
            if list1!.val < list2!.val {
                node!.next = list1
                list1 = list1!.next
            } else {
                node!.next = list2
                list2 = list2!.next
            }
            node = node!.next
        }

        if list1 != nil {
            node!.next = list1
        }
        if list2 != nil {
            node!.next = list2
        }

        return dummy.next
    }
}
