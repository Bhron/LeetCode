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
    func levelOrderBottom(root: TreeNode?) -> [[Int]] {
        if root == nil {
            return [[Int]]()
        }

        var reversedLevels = [[Int]]()
        var queue = [TreeNode?]()

        queue.append(root)
        while !queue.isEmpty {
            var currentLevel = [Int]()

            let currentLevelCount = queue.count
            for _ in 0..<currentLevelCount {
                let node = queue.first!
                queue.removeFirst()

                currentLevel.append(node!.val)

                if node!.left != nil {
                    queue.append(node!.left)
                }
                if node!.right != nil {
                    queue.append(node!.right)
                }
            }

            reversedLevels.append(currentLevel)
        }

        var levels = [[Int]]()

        while !reversedLevels.isEmpty {
            levels.append(reversedLevels.last!)
            reversedLevels.removeLast()
        }

        return levels
    }
}
