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
var sortList = function(head) {
    if (head === null) {
        return null
    }

    return mergeSort(head)
};

var mergeSort = function(head) {
    if (head === null || head.next === null) {
        return head
    }

    var mid = getMiddle(head)
    var left = head
    var right = mid.next
    mid.next = null

    var sortedLeft = mergeSort(left)
    var sortedRight = mergeSort(right)

    return merge(sortedLeft, sortedRight)
}

var getMiddle = function(head) {
    if (head === null) {
        return null
    }

    var slow = head
    var fast = head.next

    while (fast !== null && fast.next !== null) {
        slow = slow.next
        fast = fast.next.next
    }

    return slow
}

var merge = function(headA, headB) {
    var dummy = new ListNode(0)

    var node = dummy
    while (headA !== null && headB !== null) {
        if (headA.val < headB.val) {
            node.next = headA
            headA = headA.next
        } else {
            node.next = headB
            headB = headB.next
        }
        node = node.next
    }

    if (headA !== null) {
        node.next = headA
    }
    if (headB !== null) {
        node.next = headB
    }

    return dummy.next
}
