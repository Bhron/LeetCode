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
    func isSymmetric(root: TreeNode?) -> Bool {
        if root == nil {
            return true
        }

        return helper(root!.left, root!.right)
    }

    private func helper(root1: TreeNode?, _ root2: TreeNode?) -> Bool {
        if root1 == nil && root2 == nil {
            return true
        }

        if root1 == nil && root2 != nil || root1 != nil && root2 == nil {
            return false
        }

        if root1!.val != root2!.val {
            return false
        }

        return helper(root1!.left, root2!.right) && helper(root1!.right, root2!.left)
    }
}
