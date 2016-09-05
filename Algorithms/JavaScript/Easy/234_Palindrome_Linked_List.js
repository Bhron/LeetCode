/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

// O(n) Time Complexity, O(1) Space Complexity

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if (head === null) {
        return true
    }

    var mid = getMiddle(head)
    var left = head
    var right = mid.next
    mid.next = null

    right = reverse(right)

    while (right !== null) {
        if (left.val !== right.val) {
            return false
        }
        left = left.next
        right = right.next
    }
    return true
};

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

var reverse = function(head) {
    if (head === null) {
        return null
    }

    var previous = null
    while (head !== null) {
        var tmp = head.next
        head.next = previous
        previous = head
        head = tmp
    }

    return previous
}
