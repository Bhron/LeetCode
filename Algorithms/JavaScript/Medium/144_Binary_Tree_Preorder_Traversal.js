/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    var values = [];

    if (root === null) {
        return values;
    }

    var stack = [];
    stack.unshift(new Pair(null, root, Type.Node));

    while (stack.length > 0) {
        var top = stack.shift();
        if (top.type === Type.Value) {
            values.push(top.val);
        } else {
            var node = top.node;
            if (node.right !== null) {
                stack.unshift(new Pair(null, node.right, Type.Node));
            }
            if (node.left !== null) {
                stack.unshift(new Pair(null, node.left, Type.Node));
            }
            stack.unshift(new Pair(node.val, null, Type.Value));
        }
    }

    return values;
};

var Type = {
    Value: 0,
    Node: 1
};

function Pair(val, node, type) {
    this.val = val;
    this.node = node;
    this.type = type;
}
