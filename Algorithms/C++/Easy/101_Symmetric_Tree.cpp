// Recursion, O(n) Time, O(n) Space (Stack call)
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }

        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        if (root1->val != root2->val) {
            return false;
        }

        return helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }
};

// Iterative, O(n) Time, O(n) Space
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode* root1 = q.front();
            q.pop();

            TreeNode* root2 = q.front();
            q.pop();

            if (root1 == NULL && root2 == NULL) {
                continue;
            }
            if (root1 == NULL || root2 == NULL || root1->val != root2->val) {
                return false;
            }

            q.push(root1->left);
            q.push(root2->right);

            q.push(root1->right);
            q.push(root2->left);
        }

        return true;
    }
};
