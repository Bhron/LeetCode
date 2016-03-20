/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;

        while (!s.empty()) {
            s.pop();
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || cur != NULL;
    }

    /** @return the next smallest number */
    int next() {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();

        int val = cur->val;

        cur = cur->right;

        return val;
    }
private:
    TreeNode* cur;
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
