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
    func addTwoNumbers(l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        if l2 == nil {
            return l1
        }

        let dummy = ListNode(0)
        var head: ListNode? = dummy, carry = 0, list1 = l1, list2 = l2
        while carry != 0 || list1 != nil || list2 != nil {
            var sum = 0

            if list1 != nil {
                sum += list1!.val
                list1 = list1!.next
            }
            if list2 != nil {
                sum += list2!.val
                list2 = list2!.next
            }
            sum += carry

            carry = sum / 10
            sum %= 10

            let node = ListNode(sum)
            head!.next = node
            head = head!.next
        }

        return dummy.next
    }
}
