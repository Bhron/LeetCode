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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        stack<TreeNode*> s;
        TreeNode* cur = root;

        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            values.push_back(cur->val);
            cur = cur->right;
        }

        return values;
    }
};
