/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        ResultType result = helper(root);

        return result.is_balanced;
    }
private:
    class ResultType {
    public:
        bool is_balanced;
        int depth;

        ResultType(bool is_balanced = true, int depth = 0) {
            this->is_balanced = is_balanced;
            this->depth = depth;
        }
    };

    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType();
        }

        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        if (!left.is_balanced || !right.is_balanced || abs(left.depth - right.depth) > 1) {
            return ResultType(false, 0);
        }
        return ResultType(true, max(left.depth, right.depth) + 1);
    }
};
