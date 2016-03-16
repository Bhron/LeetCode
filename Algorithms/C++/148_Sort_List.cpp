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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = get_middle(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* sorted_left = sortList(head);
        ListNode* sorted_right = sortList(right);

        return merge(sorted_left, sorted_right);
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

    ListNode* merge(ListNode* headA, ListNode* headB) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while (headA != NULL && headB != NULL) {
            if (headA->val < headB->val) {
                node->next = headA;
                headA = headA->next;
            } else {
                node->next = headB;
                headB = headB->next;
            }
            node = node->next;
        }

        if (headA != NULL) {
            node->next = headA;
        }
        if (headB != NULL) {
            node->next = headB;
        }

        return dummy.next;
    }
};
