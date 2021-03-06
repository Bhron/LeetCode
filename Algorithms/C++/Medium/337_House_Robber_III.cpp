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
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        vector<int> result = helper(root);

        return max(result[0], result[1]);
    }
private:
    vector<int> helper(TreeNode* root) {
        if (root == NULL) {
            return vector<int> { 0, 0 };
        }

        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);

        vector<int> F(2, 0);
        F[0] = max(left[0], left[1]) + max(right[0], right[1]);
        F[1] = left[0] + right[0] + root->val;

        return F;
    }
};
