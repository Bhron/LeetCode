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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }

                if (i == level_size - 1) {
                    values.push_back(node->val);
                }
            }
        }

        return values;
    }
};
