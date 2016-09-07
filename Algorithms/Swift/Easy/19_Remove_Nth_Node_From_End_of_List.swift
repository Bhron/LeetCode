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
    func removeNthFromEnd(head: ListNode?, _ n: Int) -> ListNode? {
        if head == nil || n <= 0 {
            return head
        }
    
        let dummy = ListNode(0)
        dummy.next = head
        
        var node: ListNode? = dummy
        for i in 0 ..< n {
            if node == nil {
                return head
            }
            node = node!.next
        }
        
        var tail = node
        node = dummy
        while tail!.next != nil {
            node = node!.next
            tail = tail!.next
        }
        
        let nextNode = node!.next
        node!.next = nextNode!.next
        
        return dummy.next
    }
}
