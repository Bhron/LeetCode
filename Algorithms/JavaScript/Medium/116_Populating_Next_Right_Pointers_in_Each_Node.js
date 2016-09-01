/**
 * Definition for binary tree with next pointer.
 * function TreeLinkNode(val) {
 *     this.val = val;
 *     this.left = this.right = this.next = null;
 * }
 */

/**
 * @param {TreeLinkNode} root
 * @return {void} Do not return anything, modify tree in-place instead.
 */
var connect = function(root) {
    if (root === null) {
        return
    }

    var queue = []
    queue.push(root)

    while (queue.length > 0) {
        var currentLevelSize = queue.length
        for (var i = 0; i < currentLevelSize; i++) {
            var node = queue.shift()
            if (i < currentLevelSize - 1) {
                node.next = queue[0]
            }

            if (node.left !== null) {
                queue.push(node.left)
            }
            if (node.right !== null) {
                queue.push(node.right)
            }
        }
    }
};
