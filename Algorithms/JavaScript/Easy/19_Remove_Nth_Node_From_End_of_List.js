/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    if (head === null || n <= 0) {
        return head
    }

    var dummy = new ListNode(0)
    dummy.next = head

    var node = dummy
    for (var i = 0; i < n; i++) {
        if (node === null) {
            return head
        }
        node = node.next
    }

    var tail = node
    node = dummy
    while (tail.next !== null) {
        node = node.next
        tail = tail.next
    }

    var nextNode = node.next
    node.next = nextNode.next

    return dummy.next

};
