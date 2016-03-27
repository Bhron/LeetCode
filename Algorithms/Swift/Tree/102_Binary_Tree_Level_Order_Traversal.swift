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
    func levelOrder(root: TreeNode?) -> [[Int]] {
        var values = [[Int]]()

        if root == nil {
            return values
        }

        var queue = [TreeNode?]()
        queue.append(root);

        while !queue.isEmpty {
            var levelValues = [Int]()
            let levelSize = queue.count

            for var i = 0; i < levelSize; i++ {
                let node = queue.first!
                queue.removeFirst()

                levelValues.append(node!.val)

                if let left = node!.left {
                    queue.append(left)
                }
                if let right = node!.right {
                    queue.append(right)
                }
            }

            values.append(levelValues)
        }

        return values
    }
}
