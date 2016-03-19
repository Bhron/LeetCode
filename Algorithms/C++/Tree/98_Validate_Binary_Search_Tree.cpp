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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        ResultType result = helper(root);

        return result.is_valid;
    }
private:
    class ResultType {
    public:
        bool is_valid;
        int min_val;
        int max_val;

        ResultType(bool is_valid = true, int min_val = INT_MAX, int max_val = INT_MIN) {
            this->is_valid = is_valid;
            this->min_val = min_val;
            this->max_val = max_val;
        }
    };

    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType();
        }

        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        if (!left.is_valid || !right.is_valid ||
            root->left != NULL && left.max_val >= root->val ||
            root->right != NULL && right.min_val <= root->val) {
            return ResultType(false, 0, 0);
        }

        return ResultType(true, min(left.min_val, root->val), max(right.max_val, root->val));
    }
};
