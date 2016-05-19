/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }

        queue<TreeLinkNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();

            for (int i = 0; i < level_size; i++) {
                TreeLinkNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }

                if (i < level_size - 1) {
                    node->next = q.front();
                }
            }
        }
    }
};
