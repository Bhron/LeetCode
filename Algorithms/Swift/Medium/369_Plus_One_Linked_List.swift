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
    func plusOne(head: ListNode?) -> ListNode? {
        if head == nil {
            return nil
        }
        
        let reversedHead = reverse(head)
        addOne(reversedHead)
        
        return reverse(reversedHead)
    }
    
    private func reverse(head: ListNode?) -> ListNode? {
        if head == nil {
            return nil
        }
        
        var previousNode: ListNode!
        var node = head
        while node != nil {
            let tmp = node?.next
            node?.next = previousNode
            previousNode = node
            node = tmp
        }
        
        return previousNode
    }
    
    private func addOne(head: ListNode?) {
        if head == nil {
            return
        }
        
        var carry = 1
        var node = head
        var previousNode: ListNode?
        while node != nil {
            node!.val += carry
            
            carry = node!.val / 10
            node!.val %= 10
            
            previousNode = node
            node = node?.next
        }
        
        if carry != 0 {
            previousNode?.next = ListNode(carry)
        }
    }
}
