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
var deleteDuplicates = function(head) {
    if (head === null) {
        return null
    }

    var currentNode = head
    while (currentNode.next !== null) {
        var value = currentNode.val
        if (currentNode.next.val == value) {
            var node = currentNode.next
            while (node !== null && node.val === value) {
                node = node.next
            }
            currentNode.next = node
        } else {
            currentNode = currentNode.next
        }
    }

    return head
};
