/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (head === null || head.next === null) {
        return head
    }

    var dummy = new ListNode(0)
    dummy.next = head

    var node = dummy
    while (node.next !== null && node.next.next !== null) {
        var node1 = node.next
        var node2 = node1.next

        node1.next = node2.next
        node.next = node2
        node2.next = node1
        node = node1
    }

    return dummy.next
};
