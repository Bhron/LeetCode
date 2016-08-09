/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (root === null) {
        return 0
    }

    var leftDepth  = maxDepth(root.left)
    var rightDepth = maxDepth(root.right)

    return Math.max(leftDepth, rightDepth) + 1
};
