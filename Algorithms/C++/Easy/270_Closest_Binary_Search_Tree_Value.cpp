// Iterative
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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;

        while (root != NULL) {
            if (abs(root->val - target) < abs(closest - target)) {
                closest = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }

        return closest;
    }
};

// Recursion
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int cur = root->val;
        TreeNode* child = target < cur ? root->left : root->right;

        if (child == NULL) {
            return cur;
        }
        int child_val = closestValue(child, target);

        return abs(cur - target) < abs(child_val - target) ? cur : child_val;
    }
};
