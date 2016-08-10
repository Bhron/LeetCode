/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if (root === null) {
        return root
    }

    var invertLeft  = invertTree(root.left)
    var invertRight = invertTree(root.right)

    var tmp = root.left
    root.left = root.right
    root.right = tmp

    return root
};
