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
        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        while (node->next != NULL && node->next->next != NULL) {
            if (node->next->val == node->next->next->val) {
                int val = node->next->val;

                while (node->next != NULL && node->next->val == val) {
                    ListNode* tmp = node->next;
                    node->next = node->next->next;
                    delete tmp;
                }
            } else {
                node = node->next;
            }
        }

        return dummy.next;
    }
};
