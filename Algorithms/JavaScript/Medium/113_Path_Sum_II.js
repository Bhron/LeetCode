/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    var paths = []
    
    if (root === null) {
        return paths
    }
    
    var path = []
    helper(root, sum, path, paths)
    
    return paths
};

var helper = function(root, sum, path, paths) {
    if (root === null) {
        return
    }
    
    path.push(root.val)
    
    if (root.left === null && root.right === null) {
        if (root.val === sum) {
            paths.push(path.slice())
        }
    } else {
        helper(root.left, sum - root.val, path, paths)
        helper(root.right, sum - root.val, path, paths)
    }
    
    path.pop()
}
