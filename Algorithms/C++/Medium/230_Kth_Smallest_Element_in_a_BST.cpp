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

        TreeNode* node;
        TreeNode* cur = root;
        int counter = 0;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }

            node = s.top();
            counter++;
            s.pop();

            if (counter == k) {
                break;
            }

            cur = node->right;
        }

        return node->val;
    }
};

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
        int left_node_num = node_num(root->left);

        if (left_node_num + 1 == k) {
            return root->val;
        } else if (k < left_node_num + 1) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k - left_node_num - 1);
        }
    }
private:
    int node_num(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return node_num(root->left) + node_num(root->right) + 1;
    }
};
