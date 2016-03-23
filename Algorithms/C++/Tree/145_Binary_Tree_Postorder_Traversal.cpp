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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        stack<TreeNode*> s;
        s.push(root);

        TreeNode* prev = NULL;
        TreeNode* cur;

        while (!s.empty()) {
            cur = s.top();

            if (prev == NULL || prev->left == cur || prev->right == cur) {
                if (cur->left != NULL) {
                    s.push(cur->left);
                } else if (cur->right != NULL) {
                    s.push(cur->right);
                }
            } else if (cur->left == prev) {
                if (cur->right != NULL) {
                    s.push(cur->right);
                }
            } else {
                values.push_back(cur->val);
                s.pop();
            }

            prev = cur;
        }

        return values;
    }
};
