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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool is_left_to_right = true;
        while (!q.empty()) {
            vector<int> level_values;
            int level_size = q.size();
            stack<int> s;

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }

                if (is_left_to_right) {
                    level_values.push_back(node->val);
                } else {
                    s.push(node->val);
                }
            }

            if (!is_left_to_right) {
                while (!s.empty()) {
                    level_values.push_back(s.top());
                    s.pop();
                }
            }

            values.push_back(level_values);
            is_left_to_right = !is_left_to_right;
        }

        return values;
    }
};
