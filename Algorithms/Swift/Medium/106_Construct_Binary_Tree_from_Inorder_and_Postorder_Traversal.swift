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
    func buildTree(inorder: [Int], _ postorder: [Int]) -> TreeNode? {
        if inorder.isEmpty || postorder.isEmpty || inorder.count != postorder.count {
            return nil
        }
        
        return helper(inorder: inorder, inorderStartIndex: 0, inorderEndIndex: inorder.count - 1, postorder: postorder, postorderStartIndex: 0, postorderEndIndex: postorder.count - 1)
    }
    
    private func helper(inorder inorder: [Int], inorderStartIndex: Int, inorderEndIndex: Int, postorder: [Int], postorderStartIndex: Int, postorderEndIndex: Int) -> TreeNode? {
        if inorderStartIndex > inorderEndIndex {
            return nil
        }
        
        let rootVal = postorder[postorderEndIndex]
        let root    = TreeNode(rootVal)
        
        var inorderIndex = 0
        for i in inorderStartIndex...inorderEndIndex {
            if inorder[i] == rootVal {
                inorderIndex = i
                break
            }
        }
        
        let length = inorderIndex - inorderStartIndex
        
        root.left  = helper(inorder: inorder, inorderStartIndex: inorderStartIndex, inorderEndIndex: inorderIndex - 1, postorder: postorder, postorderStartIndex: postorderStartIndex, postorderEndIndex: postorderStartIndex + length - 1) 
        root.right = helper(inorder: inorder, inorderStartIndex: inorderIndex + 1, inorderEndIndex: inorderEndIndex, postorder: postorder, postorderStartIndex: postorderStartIndex + length, postorderEndIndex: postorderEndIndex - 1)
        
        return root
    }
}
