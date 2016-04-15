/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        int len = length(head);
        cur = head;

        return helper(len);
    }
private:
    ListNode* cur;

    int length(ListNode* head) {
        int len = 0;

        while (head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    TreeNode* helper(int n) {
        if (n <= 0) {
            return NULL;
        }

        TreeNode* left = helper(n / 2);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* right = helper(n - n / 2 - 1);

        root->left = left;
        root->right = right;

        return root;
    }
};
