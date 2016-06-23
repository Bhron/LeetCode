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
    func sumNumbers(root: TreeNode?) -> Int {
        var sum = 0

        helper(root, currentNumber: 0, sum: &sum)

        return sum
    }

    private func helper(root: TreeNode?, currentNumber: Int, inout sum: Int) {
        if root == nil {
            return
        }

        var number = currentNumber
        number *= 10
        number += root!.val

        if root!.left == nil && root!.right == nil {
            sum += number
        }

        helper(root!.left, currentNumber: number, sum: &sum)
        helper(root!.right, currentNumber: number, sum: &sum)
    }
}
