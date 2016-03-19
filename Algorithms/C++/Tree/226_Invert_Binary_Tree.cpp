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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* inverted_left = invertTree(root->left);
        TreeNode* inverted_right = invertTree(root->right);

        root->left = inverted_right;
        root->right = inverted_left;

        return root;
    }
};
