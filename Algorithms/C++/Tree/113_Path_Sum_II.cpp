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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;

        if (root == NULL) {
            return paths;
        }

        vector<int> path;
        helper(paths, path, root, sum);

        return paths;
    }
private:
    void helper(vector<vector<int>>& paths, vector<int>& path, TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                paths.push_back(path);
            }
        } else {
            helper(paths, path, root->left, sum - root->val);
            helper(paths, path, root->right, sum - root->val);
        }

        path.pop_back();
    }
};
