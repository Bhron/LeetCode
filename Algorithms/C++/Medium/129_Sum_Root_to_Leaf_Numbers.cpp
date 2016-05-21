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
    int sumNumbers(TreeNode* root) {
        sum = 0;
        vector<int> path;

        helper(path, root);

        return sum;
    }
private:
    int sum;

    void helper(vector<int>& path, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            sum += get_number(path);
        } else {
            helper(path, root->left);
            helper(path, root->right);
        }

        path.pop_back();
    }

    int get_number(const vector<int>& path) {
        int result = 0;

        for (int i = 0; i < path.size(); i++) {
            result *= 10;
            result += path[i];
        }

        return result;
    }
};
