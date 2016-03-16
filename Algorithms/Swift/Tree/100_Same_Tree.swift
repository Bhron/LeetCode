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
    func isSameTree(p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil {
            return true
        } else if p == nil && q != nil || p != nil && q == nil {
            return false
        }

        if p!.val != q!.val {
            return false
        }

        return isSameTree(p!.left, q!.left) && isSameTree(p!.right, q!.right)
    }
}
