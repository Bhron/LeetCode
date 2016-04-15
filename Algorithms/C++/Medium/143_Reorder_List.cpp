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
    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }

        ListNode* mid = get_middle(head);
        ListNode* right_reversed = reverse(mid->next);
        mid->next = NULL;

        merge(head, right_reversed);
    }
private:
    ListNode* get_middle(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }

    void merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        for (int i = 1; head1 != NULL && head2 != NULL; i++) {
            if (i % 2 != 0) {
                node->next = head1;
                head1 = head1->next;
            } else {
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
        }

        if (head1 != NULL) {
            node->next = head1;
        }
        if (head2 != NULL) {
            node->next = head2;
        }
    }
};
