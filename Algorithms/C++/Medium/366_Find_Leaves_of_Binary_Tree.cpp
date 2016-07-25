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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;

        if (root == NULL) {
            return leaves;
        }

        vector<int> current_leaves;
        while (root->left != NULL || root->right != NULL) {
            helper(root, current_leaves);
            leaves.push_back(current_leaves);
            current_leaves.clear();
        }
        leaves.push_back(vector<int>{ root->val });

        return leaves;
    }
private:
    bool helper(TreeNode* root, vector<int>& leaves) {
        if (root == NULL) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return true;
        }

        bool left = helper(root->left, leaves);
        if (left == true) {
            root->left = NULL;
        }

        bool right = helper(root->right, leaves);
        if (right == true) {
            root->right = NULL;
        }

        return false;
    }
};
