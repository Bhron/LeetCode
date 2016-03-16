/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* node = head;
        while (node->next != NULL) {
            if (node->val == node->next->val) {
                int val = node->val;

                ListNode* last = node->next;
                while (last != NULL && last->val == val) {
                    ListNode* tmp = last;
                    last = last->next;
                    delete tmp;
                }
                node->next = last;
            } else {
                node = node->next;
            }
        }

        return head;
    }
};
