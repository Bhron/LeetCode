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
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;

        if (root == NULL) {
            return sum;
        }

        helper(root, false);

        return sum;
    }
private:
    int sum;

    void helper(TreeNode* root, bool isLeft) {
        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) {
            if (isLeft) {
                sum += root->val;
            }
            return;
        }

        helper(root->left, true);
        helper(root->right, false);
    }
};
