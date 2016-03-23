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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;

        TreeNode* cur = root;
        int counter = 0;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode* node = s.top();
            counter++;
            s.pop();

            if (counter == k) {
                return node->val;
            }

            cur = node->right;
        }
    }
};
