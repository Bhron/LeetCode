/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    if (head === null) {
        return null
    }

    var dummy = new ListNode(0)
    dummy.next = head

    var node = dummy
    while (node.next !== null) {
        var nextNode = node.next
        if (nextNode.val === val) {
            node.next = nextNode.next
        } else {
            node = nextNode
        }
    }

    return dummy.next
};
