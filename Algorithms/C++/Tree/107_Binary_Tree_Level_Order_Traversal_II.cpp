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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level_values;
            int level_size = q.size();

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level_values.push_back(node->val);

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            values.insert(values.begin(), level_values);
        }

        return values;
    }
};
