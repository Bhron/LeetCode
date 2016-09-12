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
    func pathSum(root: TreeNode?, _ sum: Int) -> [[Int]] {
        var paths = [[Int]]()
        
        if root == nil {
            return paths
        }
        
        var path = [Int]()
        helper(root, sum: sum, path: &path, paths: &paths)
        
        return paths
    }
    
    private func helper(root: TreeNode?, sum: Int, inout path: [Int], inout paths: [[Int]]) {
        if root == nil {
            return
        }
        
        path.append(root!.val)
        
        if root!.left == nil && root!.right == nil {
            if root!.val == sum {
                paths.append(path)
            }
            path.popLast()
            return
        }
        
        let value = root!.val
        helper(root!.left, sum: sum - value, path: &path, paths: &paths)
        helper(root!.right, sum: sum - value, path: &path, paths: &paths)
        
        path.popLast()
    }
}
