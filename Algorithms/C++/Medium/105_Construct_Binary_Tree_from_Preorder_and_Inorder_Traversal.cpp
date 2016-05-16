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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return NULL;
        }

        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& preorder, int preorder_start, int preorder_end, vector<int>& inorder, int inorder_start, int inorder_end) {
        if (inorder_start > inorder_end) {
            return NULL;
        }

        int root_val = preorder[preorder_start];
        TreeNode* root = new TreeNode(root_val);

        int inorder_root_index;
        for (inorder_root_index = inorder_start; inorder_root_index <= inorder_end && inorder[inorder_root_index] != root_val; inorder_root_index++) {
            ;
        }
        int len = inorder_root_index - inorder_start;

        root->left = helper(preorder, preorder_start + 1, preorder_start + 1 + len - 1, inorder, inorder_start, inorder_root_index - 1);
        root->right = helper(preorder, preorder_start + 1 + len - 1 + 1, preorder_end, inorder, inorder_root_index + 1, inorder_end);

        return root;
    }
};
