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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_dummy(0);
        ListNode even_dummy(0);

        ListNode* odd = &odd_dummy;
        ListNode* even = &even_dummy;

        for (int i = 1; head != NULL; i++) {
            if (i % 2 != 0) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }

        even->next = NULL;
        odd->next = even_dummy.next;

        return odd_dummy.next;
    }
};
