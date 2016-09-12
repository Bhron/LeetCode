/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    if (head === null) {
        return null
    }
    
    var dummy1 = new ListNode(0)
    var dummy2 = new ListNode(0)
    
    var node = head, node1 = dummy1, node2 = dummy2
    while (node !== null) {
        if (node.val < x) {
            node1.next = node
            node1 = node1.next
        } else {
            node2.next = node
            node2 = node2.next
        }
        node = node.next
    }
    
    node1.next = dummy2.next
    node2.next = null
    
    return dummy1.next
};
