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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        while (node->next != NULL && node->next->next != NULL) {
            ListNode* node1 = node->next;
            ListNode* node2 = node1->next;

            node1->next = node2->next;
            node2->next = node1;
            node->next = node2;

            node = node1;
        }

        return dummy.next;
    }
};
