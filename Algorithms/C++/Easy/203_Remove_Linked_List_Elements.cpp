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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        while (node->next != NULL) {
            if (node->next->val == val) {
                ListNode* tmp = node->next;
                node->next = node->next->next;
                delete tmp;
            } else {
                node = node->next;
            }
        }

        return dummy.next;
    }
};
