/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    var levelsValues = []

    if (root === null) {
        return levelsValues
    }

    var queue = [root]
    while (queue.length > 0) {
        var levelValues = []

        var queueLength = queue.length
        for (var i = 0; i < queueLength; i++) {
            var node = queue.shift()
            levelValues.push(node.val)

            if (node.left !== null) {
                queue.push(node.left)
            }
            if (node.right !== null) {
                queue.push(node.right)
            }
        }

        levelsValues.push(levelValues)
    }

    return levelsValues
};
