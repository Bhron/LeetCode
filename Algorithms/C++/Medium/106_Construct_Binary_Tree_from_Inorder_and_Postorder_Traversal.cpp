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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return NULL;
        }

        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& inorder, int inorder_start, int inorder_end, vector<int>& postorder, int postorder_start, int postorder_end) {
        if (inorder_start > inorder_end) {
            return NULL;
        }

        int root_val = postorder[postorder_end];
        TreeNode* root = new TreeNode(root_val);

        int inorder_root_index;
        for (inorder_root_index = inorder_start; inorder_root_index <= inorder_end && inorder[inorder_root_index] != root_val; inorder_root_index++) {
            ;
        }
        int len = inorder_root_index - inorder_start;

        root->left = helper(inorder, inorder_start, inorder_root_index - 1, postorder, postorder_start, postorder_start + len - 1);
        root->right = helper(inorder, inorder_root_index + 1, inorder_end, postorder, postorder_start + len - 1 + 1, postorder_end - 1);

        return root;
    }
};
