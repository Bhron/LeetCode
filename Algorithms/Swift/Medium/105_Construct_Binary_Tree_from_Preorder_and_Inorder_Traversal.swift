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
    func buildTree(preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        if preorder.isEmpty || inorder.isEmpty || preorder.count != inorder.count {
            return nil
        }

        return helper(preorder: preorder, preorderStart: 0, preorderEnd: preorder.count - 1, inorder: inorder, inorderStart: 0, inorderEnd: inorder.count - 1)
    }

    private func helper(preorder preorder: [Int], preorderStart: Int, preorderEnd: Int, inorder: [Int], inorderStart: Int, inorderEnd: Int) -> TreeNode? {
        if preorderStart > preorderEnd {
            return nil
        }

        let rootVal = preorder[preorderStart]
        let root = TreeNode(rootVal)

        var inorderIndex = 0
        for i in inorderStart...inorderEnd {
            if inorder[i] == rootVal {
                inorderIndex = i
                print(inorderIndex)
                break
            }
        }

        let length = inorderIndex - inorderStart

        root.left = helper(preorder: preorder, preorderStart: preorderStart + 1, preorderEnd: preorderStart + 1 + length - 1, inorder: inorder, inorderStart: inorderStart, inorderEnd: inorderIndex - 1)
        root.right = helper(preorder: preorder, preorderStart: preorderStart + 1 + length - 1 + 1, preorderEnd: preorderEnd, inorder: inorder, inorderStart: inorderIndex + 1, inorderEnd: inorderEnd)

        return root
    }
}
