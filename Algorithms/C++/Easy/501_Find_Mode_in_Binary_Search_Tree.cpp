// O(1) Space, assume that the implicit stack space incurred due to recursion does not count
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
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;

        maxCount = 0;
        prev = NULL;
        calculateMaxCount(root);

        prev = NULL;
        generateModes(root, modes);

        return modes;
    }

private:
    int maxCount = 0;
    int currentCount = 0;
    TreeNode* prev = NULL;

    void calculateMaxCount(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        calculateMaxCount(root->left);

        if (prev == NULL) {
            currentCount = 1;
        } else {
            if (prev->val == root->val) {
                currentCount++;
            } else {
                currentCount = 1;
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
        prev = root;

        calculateMaxCount(root->right);
    }

    void generateModes(TreeNode* root, vector<int>& modes) {
        if (root == NULL) {
            return;
        }

        generateModes(root->left, modes);

        if (prev == NULL) {
            currentCount = 1;
        } else {
            if (prev->val == root->val) {
                currentCount++;
            } else {
                currentCount = 1;
            }
        }

        if (currentCount == maxCount) {
            modes.push_back(root->val);
        }
        prev = root;

        generateModes(root->right, modes);
    }
};