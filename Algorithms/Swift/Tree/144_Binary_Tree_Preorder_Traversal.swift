/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func preorderTraversal(root: TreeNode?) -> [Int] {
        var values = [Int]()

        if root == nil {
            return values
        }

        var node = root
        var stack = [TreeNode?]()

        while !stack.isEmpty || node != nil {
            while node != nil {
                values.append(node!.val)
                stack.append(node)
                node = node!.left
            }

            let current = stack.last!
            stack.removeLast()

            node = current!.right
        }

        return values
    }
}
