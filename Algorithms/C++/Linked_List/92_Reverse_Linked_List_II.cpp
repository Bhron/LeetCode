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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m <= 0 || m >= n) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        for (int i = 0; i < m - 1; i++) {
            if (node->next == NULL) {
                return NULL;
            }
            node = node->next;
        }

        ListNode* m_node = node->next;
        if (m_node == NULL) {
            return NULL;
        }
        ListNode* prev_m = node;


        ListNode* prev = m_node;
        node = m_node->next;
        for (int i = 0; i < n - m; i++) {
            if (node == NULL) {
                return NULL;
            }
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        prev_m->next = prev;
        m_node->next = node;

        return dummy.next;
    }
};
