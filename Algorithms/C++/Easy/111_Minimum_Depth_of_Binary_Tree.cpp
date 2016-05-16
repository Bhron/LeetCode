/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right != NULL) {
            return minDepth(root->right) + 1;
        }
        if (root->left != NULL && root->right == NULL) {
            return minDepth(root->left) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            bool found_leaf = false;
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left == NULL && node->right == NULL) {
                    found_leaf = true;
                    break;
                } else {
                    if (node->left != NULL) {
                        q.push(node->left);
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                    }
                }
            }

            if (found_leaf) {
                break;
            } else {
                depth++;
            }
        }

        return depth;
    }
};
