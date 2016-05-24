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
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        ResultType result = helper(root);

        return result.max_path;
    }
private:
    class ResultType {
    public:
        int single_path;
        int max_path;

        ResultType(int single_path, int max_path) {
            this->single_path = single_path;
            this->max_path = max_path;
        }
    };

    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType(0, INT_MIN);
        }

        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        int single_path = max(0, max(left.single_path, right.single_path) + root->val);

        int max_path = max(left.max_path, right.max_path);
        max_path = max(left.single_path + right.single_path + root->val, max_path);

        return ResultType(single_path, max_path);
    }
};
