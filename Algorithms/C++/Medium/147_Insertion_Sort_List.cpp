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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head != NULL) {
            ListNode* node = &dummy;
            while (node->next != NULL && node->next->val < head->val) {
                node = node->next;
            }

            ListNode* tmp = head->next;
            head->next = node->next;
            node->next = head;
            head = tmp;
        }

        return dummy.next;
    }
};
