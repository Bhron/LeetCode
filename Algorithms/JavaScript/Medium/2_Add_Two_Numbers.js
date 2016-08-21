/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var dummyNode = new ListNode(0)

    var node = dummyNode, carry = 0
    while (l1 !== null || l2 !== null || carry !== 0) {
        var sum = 0

        if (l1 !== null) {
            sum += l1.val
            l1 = l1.next
        }
        if (l2 !== null) {
            sum += l2.val
            l2 = l2.next
        }
        sum += carry

        carry = Math.floor(sum / 10)
        sum %= 10

        var newNode = new ListNode(sum)
        node.next = newNode
        node = node.next
    }

    return dummyNode.next
};
