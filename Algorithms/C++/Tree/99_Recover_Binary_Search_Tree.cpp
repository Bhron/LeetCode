class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;

        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();

            if (prev != NULL && prev->val > cur->val) {
                if (node1 == NULL) {
                    node1 = prev;
                    node2 = cur;
                } else {
                    node2 = cur;
                }
            }

            prev = cur;
            cur = cur->right;
        }

        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }
};
