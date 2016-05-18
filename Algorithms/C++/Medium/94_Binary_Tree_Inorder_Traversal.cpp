/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Non-Recursion
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

// Non-Recursion, Hash Table
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        stack<TreeNode*> s;
        unordered_map<TreeNode*, bool> left_child_visited;

        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            if (node->left != NULL && !left_child_visited[node->left]) {
                s.push(node->left);
                left_child_visited[node->left] = true;
            } else {
                values.push_back(node->val);
                s.pop();

                if (node->right != NULL) {
                    s.push(node->right);
                }
            }
        }

        return values;
    }
};

// Recursion
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> values;

        helper(root, values);

        return values;
    }
private:
    void helper(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        }

        helper(root->left, values);
        values.push_back(root->val);
        helper(root->right, values);
    }
};
