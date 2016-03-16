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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_dummy(0);
        ListNode other_dummy(0);

        ListNode* less = &less_dummy;
        ListNode* other = &other_dummy;

        while (head != NULL) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                other->next = head;
                other = other->next;
            }
            head = head->next;
        }

        other->next = NULL;
        less->next = other_dummy.next;

        return less_dummy.next;
    }
};
