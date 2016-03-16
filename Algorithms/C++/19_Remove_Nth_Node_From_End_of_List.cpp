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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        for (int i = 0; i < n; i++) {
            node = node->next;
        }

        ListNode* prev = &dummy;
        while (node->next != NULL) {
            prev = prev->next;
            node = node->next;
        }

        ListNode* tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;

        return dummy.next;
    }
};
