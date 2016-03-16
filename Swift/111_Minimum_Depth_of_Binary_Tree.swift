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
    func minDepth(root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        
        if root!.left != nil && root!.right != nil {
            return min(minDepth(root!.left), minDepth(root!.right)) + 1
        } else if root!.left != nil {
            return minDepth(root!.left) + 1
        } else {
            return minDepth(root!.right) + 1
        }
    }
}
