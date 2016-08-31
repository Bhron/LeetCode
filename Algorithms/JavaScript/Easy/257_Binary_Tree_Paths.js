/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    var paths = []

    var currentPathValues = []
    helper(root, currentPathValues, paths)

    return paths
};

var helper = function(root, currentPathValues, paths) {
    if (root === null) {
        return
    }

    currentPathValues.push(root.val)

    if (root.left === null && root.right === null) {
        paths.push(generatePath(currentPathValues))
    } else {
        helper(root.left, currentPathValues, paths)
        helper(root.right, currentPathValues, paths)
    }

    currentPathValues.pop()
}

var generatePath = function(pathValues) {
    if (pathValues.length === 0) {
        return ""
    }

    var path = ""
    for (var i = 0; i < pathValues.length - 1; i++) {
        path += pathValues[i] + "->"
    }

    path += pathValues[pathValues.length - 1]

    return path
}
