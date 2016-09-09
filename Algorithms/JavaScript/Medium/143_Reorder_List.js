/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (head === null) {
        return
    }
    
    var middle = getMiddle(head)
    var list1 = head
    var list2 = middle.next
    middle.next = null
    
    list2 = reverseList(list2)
    zipList(list1, list2)
};

var getMiddle = function(head) {
    if (head === null) {
        return null
    }
    
    var slow = head, fast = head.next
    while (fast !== null && fast.next !== null) {
        slow = slow.next
        fast = fast.next.next
    }
    
    return slow
}

var reverseList = function(head) {
    var previous = null
    
    while (head !== null) {
        var nextNode = head.next
        head.next = previous
        previous = head
        head = nextNode
    }
    
    return previous
}

var zipList = function(head1, head2) {
    var dummy = new ListNode(0)
    var node = dummy, i = 0
    while (head1 !== null && head2 !== null) {
        if (i % 2 === 0) {
            node.next = head1
            head1 = head1.next
        } else {
            node.next = head2
            head2 = head2.next
        }
        node = node.next
        i++
    }
    
    if (head1 !== null) {
        node.next = head1
    }
    if (head2 !== null) {
        node.next = head2
    }
    
    return dummy.next
}
