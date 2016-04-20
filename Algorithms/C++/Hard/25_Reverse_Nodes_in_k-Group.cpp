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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) {
            return head;
        }

        int len = length(head);
        int n = len / k;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev_tail = &dummy;;

        while (n > 0) {
            ListNode* cur_tail = prev_tail->next;
            ListNode* prev = cur_tail;
            ListNode* node = prev->next;;
            for (int i = 0; i < k - 1; i++) {
                ListNode* tmp = node->next;
                node->next = prev;
                prev = node;
                node = tmp;
            }

            prev_tail->next = prev;
            cur_tail->next = node;

            prev_tail = cur_tail;

            n--;
        }

        return dummy.next;
    }
private:
    int length(ListNode* head) {
        int len = 0;

        while (head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }
};
