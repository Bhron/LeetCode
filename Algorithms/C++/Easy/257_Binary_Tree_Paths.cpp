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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;

        helper(paths, "", root);

        return paths;
    }
private:
    void helper(vector<string>& paths, string path, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path);
            return;
        }

        path += "->";
        helper(paths, path, root->left);
        helper(paths, path, root->right);
    }
};
