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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        ResultType result = helper(root);

        return result.longest_length;
    }
private:
    class ResultType {
    public:
        int cur_length;
        int longest_length;

        ResultType(int cur_length, int longest_length) {
            this->cur_length = cur_length;
            this->longest_length = longest_length;
        }
    };

    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType(0, 0);
        }

        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        ResultType result(1, 1);

        if (root->left != NULL && root->val + 1 == root->left->val) {
            result.cur_length = left.cur_length + 1;
            result.longest_length = max(result.longest_length, result.cur_length);
        }
        if (root->right != NULL && root->val + 1 == root->right->val) {
            result.cur_length = max(result.cur_length, right.cur_length + 1);
            result.longest_length = max(result.longest_length, result.cur_length);
        }

        result.longest_length = max(result.longest_length, left.longest_length);
        result.longest_length = max(result.longest_length, right.longest_length);

        return result;
    }
};
